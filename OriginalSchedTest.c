#include "types.h"
#include "stat.h"
#include "user.h"

struct timeVariables{
  uint creationTime;
  uint terminationTime;
  uint sleepingTime;
  int readyTime;
  uint runningTime;
};


int main(void){
  int input = 1;
  changePolicy(input);

  int p0 = fork();
  if (p0 > 0) {
    int p1 = fork();
    if (p1 > 0) {
      int p2 = fork();
      if (p2 > 0) {
        int p3 = fork();
        if (p3 > 0) {
          int p4 = fork();
          if (p4 > 0) {
            int p5 = fork();
            if (p5 > 0) {
              int p6 = fork();
              if (p6 > 0) {
                int p7 = fork();
                if (p7 > 0) {
                  int p8 = fork();
                  if (p8 > 0) {
                    int p9 = fork();
                    if (p9 > 0) {
                      // parent code
                      struct timeVariables t0 = {0, 0, 0, -1, 0};
                      struct timeVariables t1 = {0, 0, 0, -1, 0};
                      struct timeVariables t2 = {0, 0, 0, -1, 0};
                      struct timeVariables t3 = {0, 0, 0, -1, 0};
                      struct timeVariables t4 = {0, 0, 0, -1, 0};
                      struct timeVariables t5 = {0, 0, 0, -1, 0};
                      struct timeVariables t6 = {0, 0, 0, -1, 0};
                      struct timeVariables t7 = {0, 0, 0, -1, 0};
                      struct timeVariables t8 = {0, 0, 0, -1, 0};
                      struct timeVariables t9 = {0, 0, 0, -1, 0};
                      int pid0 = waitForChild(&t0);
                      int pid1 = waitForChild(&t1);
                      int pid2 = waitForChild(&t2);
                      int pid3 = waitForChild(&t3);
                      int pid4 = waitForChild(&t4);
                      int pid5 = waitForChild(&t5);
                      int pid6 = waitForChild(&t6);
                      int pid7 = waitForChild(&t7);
                      int pid8 = waitForChild(&t8);
                      int pid9 = waitForChild(&t9);

                      printf(1,"pid -> %d, TT -> %d, cbt -> %d, Waiting Time -> %d\n", pid0, (t0.terminationTime-t0.creationTime), t0.runningTime, (t0.terminationTime-t0.creationTime-t0.runningTime) );
                      printf(1,"pid -> %d, TT -> %d, cbt -> %d, Waiting Time -> %d\n", pid1, (t1.terminationTime-t1.creationTime), t1.runningTime, (t1.terminationTime-t1.creationTime-t1.runningTime) );
                      printf(1,"pid -> %d, TT -> %d, cbt -> %d, Waiting Time -> %d\n", pid2, (t2.terminationTime-t2.creationTime), t2.runningTime, (t2.terminationTime-t2.creationTime-t2.runningTime) );
                      printf(1,"pid -> %d, TT -> %d, cbt -> %d, Waiting Time -> %d\n", pid3, (t3.terminationTime-t3.creationTime), t3.runningTime, (t3.terminationTime-t3.creationTime-t3.runningTime) );
                      printf(1,"pid -> %d, TT -> %d, cbt -> %d, Waiting Time -> %d\n", pid4, (t4.terminationTime-t4.creationTime), t4.runningTime, (t4.terminationTime-t4.creationTime-t4.runningTime) );
                      printf(1,"pid -> %d, TT -> %d, cbt -> %d, Waiting Time -> %d\n", pid5, (t5.terminationTime-t5.creationTime), t5.runningTime, (t5.terminationTime-t5.creationTime-t5.runningTime) );
                      printf(1,"pid -> %d, TT -> %d, cbt -> %d, Waiting Time -> %d\n", pid6, (t6.terminationTime-t6.creationTime), t6.runningTime, (t6.terminationTime-t6.creationTime-t6.runningTime) );
                      printf(1,"pid -> %d, TT -> %d, cbt -> %d, Waiting Time -> %d\n", pid7, (t7.terminationTime-t7.creationTime), t7.runningTime, (t7.terminationTime-t7.creationTime-t7.runningTime) );
                      printf(1,"pid -> %d, TT -> %d, cbt -> %d, Waiting Time -> %d\n", pid8, (t8.terminationTime-t8.creationTime), t8.runningTime, (t8.terminationTime-t8.creationTime-t8.runningTime) );
                      printf(1,"pid -> %d, TT -> %d, cbt -> %d, Waiting Time -> %d\n", pid9, (t9.terminationTime-t9.creationTime), t9.runningTime, (t9.terminationTime-t9.creationTime-t9.runningTime) );

                      //average :
                      int ttAvr = (int) ((t0.terminationTime-t0.creationTime)
                            +(t1.terminationTime-t1.creationTime)
                            +(t2.terminationTime-t2.creationTime)
                            +(t3.terminationTime-t3.creationTime)
                            +(t4.terminationTime-t4.creationTime)
                            +(t5.terminationTime-t5.creationTime)
                            +(t6.terminationTime-t6.creationTime)
                            +(t7.terminationTime-t7.creationTime)
                            +(t8.terminationTime-t8.creationTime)
                            +(t9.terminationTime-t9.creationTime)) / 10;

                      int cbtAvr = (int) (t0.runningTime+t1.runningTime+t2.runningTime+t3.runningTime+t4.runningTime+
                            t5.runningTime+t6.runningTime+t7.runningTime+t8.runningTime+t9.runningTime) / 10;

                      int wAvr = (float) ((t0.terminationTime-t0.creationTime-t0.runningTime)
                            +(t1.terminationTime-t1.creationTime-t1.runningTime)
                            +(t2.terminationTime-t2.creationTime-t2.runningTime)
                            +(t3.terminationTime-t3.creationTime-t3.runningTime)
                            +(t4.terminationTime-t4.creationTime-t4.runningTime)
                            +(t5.terminationTime-t5.creationTime-t5.runningTime)
                            +(t6.terminationTime-t6.creationTime-t6.runningTime)
                            +(t7.terminationTime-t7.creationTime-t7.runningTime)
                            +(t8.terminationTime-t8.creationTime-t8.runningTime)
                            +(t9.terminationTime-t9.creationTime-t9.runningTime)) / 10;

                        printf(1,"----------------------------------------------------------\naverage : \n");
                        printf(1," TT avr -> %d, cbt avr -> %d, waiting time avr -> %d\n", ttAvr, cbtAvr, wAvr);
                    }
                    else{
                      for (int i = 0; i < 1000; i++) {
                        printf(1,"%d : %d\n",getpid(), i);
                      }
                    }
                  }
                  else{
                    for (int i = 0; i < 1000; i++) {
                      printf(1,"%d : %d\n",getpid(), i);
                    }
                  }
                }
                else{
                  for (int i = 0; i < 1000; i++) {
                    printf(1,"%d : %d\n",getpid(), i);
                  }
                }
              }
              else{
                for (int i = 0; i < 1000; i++) {
                  printf(1,"%d : %d\n",getpid(), i);
                }
              }
            }
            else{
              for (int i = 0; i < 1000; i++) {
                printf(1,"%d : %d\n",getpid(), i);
              }
            }
          }
          else{
            for (int i = 0; i < 1000; i++) {
              printf(1,"%d : %d\n",getpid(), i);
            }
          }
        }
        else{
          for (int i = 0; i < 1000; i++) {
            printf(1,"%d : %d\n",getpid(), i);
          }
        }
      }
      else{
        for (int i = 0; i < 1000; i++) {
          printf(1,"%d : %d\n",getpid(), i);
        }
      }
    }
    else{
      for (int i = 0; i < 1000; i++) {
        printf(1,"%d : %d\n",getpid(), i);
      }
    }

  }
  else{
    for (int i = 0; i < 1000; i++) {
      printf(1,"%d : %d\n",getpid(), i);
    }
  }
  exit();
}
