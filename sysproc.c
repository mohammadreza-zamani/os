#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

//just for test system call
int
sys_getyear(void)
{
return 1975;
}

//get ppid
int
sys_getppid(void){

  return myproc()->parent->pid;

}

int
sys_getChildren(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;

  return getChildren(pid);
}

int
sys_getCount(void){
  int input;

  if(argint(0, &input) < 0)
    return -1;

  return getCount(input);
}

int
sys_changePriority(void){
  int input;

  if(argint(0, &input) < 0)
    return -1;
  if (input > 5 || input < 1) {
    return -1;
  }
  //cprintf("%d\n",myproc()->priority);
  myproc()->priority = input;
  //cprintf("%d\n",myproc()->priority);
  return 1;
}

int
sys_changePolicy(void){
  int input;

  if(argint(0, &input) < 0)
    return -1;

  return changePolicy(input);
}

int
sys_waitForChild(void){
  struct timeVariables *tv;
  if (argptr(0, (void*)&tv, sizeof(*tv)) < 0){
    return -1;
  }
  return waitForChild(tv);
}

int
sys_ticketlockInit(void){
  ticketlockInit();
  return 1;
}

int
sys_ticketlockTest(void){

  return returnTicketValue();
}

int
sys_rwinit(void){
  rwinitProc();
  return 0;
}

int
sys_rwtest(void){
  int input;

  if(argint(0, &input) < 0)
    return -1;

  return rwtestProc(input);
}
