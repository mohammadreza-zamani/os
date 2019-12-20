#include "types.h"
#include "stat.h"
#include "user.h"

int main(void){
  int p = fork();
  int p1 = fork();
  if (p == 0){
    printf(1, "child->ppid : %d %d\n", getppid(), getpid());
  }
  if (p > 0 && p1 > 0){
    printf(1, "parent->pid : %d %d\n", getpid(), getChildren(getpid()));
    wait();
  }
  
  exit();
}
