#include "types.h"
#include "stat.h"
#include "user.h"

int main(void){
  int input = 3;
  printf(1," testing changePolicy input : %d output : %d \n",input, changePolicy(input) );

  input = 1;
  printf(1," testing changePolicy input : %d output : %d \n",input, changePolicy(input) );
  exit();

}
