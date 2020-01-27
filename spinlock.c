// Mutual exclusion spin locks.

#include "types.h"
#include "defs.h"
#include "param.h"
#include "x86.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "spinlock.h"

void
initlock(struct spinlock *lk, char *name)
{
  lk->name = name;
  lk->locked = 0;
  lk->cpu = 0;
}

void
initTicketlock(struct Ticketlock *lk, char *name)
{
  lk->name = name;
  lk->locked = 0;
  lk->q = 0;
  lk->cpu = 0;
}

void
initrwlock(struct rwlock *lk, char *name)
{
  lk->name = name;
  lk->readersIn = 0;
  lk->readersOut = 0;
  lk->lockedW = 0;
  lk->cpu = 0;
}

void
acquirerwlock(struct rwlock *lk, int type){
  pushcli(); // disable interrupts to avoid deadlock.
  if (type == 0){
    while(lk->lockedW == 1);
    fetch_and_add(&lk->readersIn, 1);
  }else if(type == 1){
    while(lk->lockedW == 1);
    xchg(&lk->lockedW, 1);
    while(lk->readersOut < lk->readersIn);
  }

  __sync_synchronize();

  // Record info about lock acquisition for debugging.
  lk->cpu = mycpu();
  getcallerpcs(&lk, lk->pcs);
}

void
acquireTicketlock(struct Ticketlock *lk){
  pushcli(); // disable interrupts to avoid deadlock.
  //if(holding(lk))
  //  panic("acquire");


  myproc()->ticket = lk->q;
  while (lk->locked < myproc()->ticket);

  __sync_synchronize();

  fetch_and_add(&lk->q, 1);
  lk->cpu = mycpu();
  getcallerpcs(&lk, lk->pcs);


}
// Acquire the lock.
// Loops (spins) until the lock is acquired.
// Holding a lock for a long time may cause
// other CPUs to waste time spinning to acquire it.
void
acquire(struct spinlock *lk)
{
  pushcli(); // disable interrupts to avoid deadlock.
  if(holding(lk))
    panic("acquire");

  // The xchg is atomic.
  while(xchg(&lk->locked, 1) != 0)
    ;

  // Tell the C compiler and the processor to not move loads or stores
  // past this point, to ensure that the critical section's memory
  // references happen after the lock is acquired.
  __sync_synchronize();

  // Record info about lock acquisition for debugging.
  lk->cpu = mycpu();
  getcallerpcs(&lk, lk->pcs);
}

void
releaserwlock(struct rwlock *lk, int type){
  lk->pcs[0] = 0;
  lk->cpu = 0;

  __sync_synchronize();
  if(type == 0){
    fetch_and_add(&lk->readersOut, 1);
  }else if(type == 1){
    xchg(&lk->lockedW, 0);
  }
  popcli();
}

void
releaseTicketlock(struct Ticketlock *lk){
  //if(!holding(lk))
  //  panic("release");

  lk->pcs[0] = 0;
  lk->cpu = 0;


  __sync_synchronize();

  fetch_and_add(&lk->locked, 1);
  popcli();
}

// Release the lock.
void
release(struct spinlock *lk)
{
  if(!holding(lk))
    panic("release");

  lk->pcs[0] = 0;
  lk->cpu = 0;

  // Tell the C compiler and the processor to not move loads or stores
  // past this point, to ensure that all the stores in the critical
  // section are visible to other cores before the lock is released.
  // Both the C compiler and the hardware may re-order loads and
  // stores; __sync_synchronize() tells them both not to.
  __sync_synchronize();

  // Release the lock, equivalent to lk->locked = 0.
  // This code can't use a C assignment, since it might
  // not be atomic. A real OS would use C atomics here.
  asm volatile("movl $0, %0" : "+m" (lk->locked) : );

  popcli();
}

// Record the current call stack in pcs[] by following the %ebp chain.
void
getcallerpcs(void *v, uint pcs[])
{
  uint *ebp;
  int i;

  ebp = (uint*)v - 2;
  for(i = 0; i < 10; i++){
    if(ebp == 0 || ebp < (uint*)KERNBASE || ebp == (uint*)0xffffffff)
      break;
    pcs[i] = ebp[1];     // saved %eip
    ebp = (uint*)ebp[0]; // saved %ebp
  }
  for(; i < 10; i++)
    pcs[i] = 0;
}

// Check whether this cpu is holding the lock.
int
holding(struct spinlock *lock)
{
  int r;
  pushcli();
  r = lock->locked && lock->cpu == mycpu();
  popcli();
  return r;
}


// Pushcli/popcli are like cli/sti except that they are matched:
// it takes two popcli to undo two pushcli.  Also, if interrupts
// are off, then pushcli, popcli leaves them off.

void
pushcli(void)
{
  int eflags;

  eflags = readeflags();
  cli();
  if(mycpu()->ncli == 0)
    mycpu()->intena = eflags & FL_IF;
  mycpu()->ncli += 1;
}

void
popcli(void)
{
  if(readeflags()&FL_IF)
    panic("popcli - interruptible");
  if(--mycpu()->ncli < 0)
    panic("popcli");
  if(mycpu()->ncli == 0 && mycpu()->intena)
    sti();
}
