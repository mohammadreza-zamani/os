#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char** argv){
  
  wait();
  wait();
  wait();
  wait();
  wait();
  printf(1,"output of this systemCall : %d \n",getCount(atoi(argv[1])));
  exit();
}
