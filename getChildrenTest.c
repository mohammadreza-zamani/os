#include "types.h"
#include "stat.h"
#include "user.h"

int main(void){
  int p1 = fork();


  if (p1 > 0){
    int p2 = fork();
    if (p2 > 0){
      printf(1 , "I am parent. my id is : %d\n", getpid());
      printf(1 , "my Children : %d\n", getChildren(getpid()));
      sleep(150);
      wait();
      wait();
    }
    else{
      sleep(50);
      printf(1 , "I am child. my id is : %d and my parent's id is : %d\n", getpid(), getppid());
      
    }
  }
  else{
   sleep(100);
   printf(1 , "I am child. my id is : %d and my parent's id is : %d\n", getpid(), getppid());
   
  }
  exit();

}
