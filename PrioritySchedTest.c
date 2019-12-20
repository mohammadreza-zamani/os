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
  int input = 2;
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
                      int p10 = fork();
                      if (p10 > 0) {
                        int p11 = fork();
                        if (p11 > 0) {
                          int p12 = fork();
                          if (p12 > 0) {
                            int p13 = fork();
                            if (p13 > 0) {
                              int p14 = fork();
                              if (p14 > 0) {
                                int p15 = fork();
                                if (p15 > 0) {
                                  int p16 = fork();
                                  if (p16 > 0) {
                                    int p17 = fork();
                                    if (p17 > 0) {
                                      int p18 = fork();
                                      if (p18 > 0) {
                                        int p19 = fork();
                                        if (p19 > 0) {
                                          int p20 = fork();
                                          if (p20 > 0) {
                                            int p21 = fork();
                                            if (p21 > 0) {
                                              int p22 = fork();
                                              if (p22 > 0) {
                                                int p23 = fork();
                                                if (p23 > 0) {
                                                  int p24 = fork();
                                                  if (p24 > 0) {
                                                    // parent code
                                                    struct timeVariables t[25];
                                                    for (int i = 0 ; i < 25 ; i++){
                                                      t[i].creationTime = 0;
                                                      t[i].terminationTime = 0;
                                                      t[i].sleepingTime = 0;
                                                      t[i].readyTime = -1;
                                                      t[i].runningTime = 0;
                                                    }
                                                    int pid[25];
                                                    for (int i = 0 ; i < 25 ; i++){
                                                      pid[i] = waitForChild(&t[i]);
                                                    }
                                                    for (int i = 0 ; i < 25 ; i++){
                                                      printf(1,"pid -> %d, TT -> %d, cbt -> %d, Waiting Time -> %d\n", pid[i], (t[i].terminationTime-t[i].creationTime), t[i].runningTime, (t[i].terminationTime-t[i].creationTime-t[i].runningTime) );
                                                    }

                                                    printf(1,"-----------------------------------------------------------------------\nfor each group \n");

                                                    // group average :
                                                    int ttAvr[5];
                                                    for (int i = 0 ; i < 5 ; i++){
                                                      ttAvr[i] = 0;
                                                      for (int j = 0 ; j < 5 ; j++){
                                                        ttAvr[i] += (t[i*5+j].terminationTime - t[i*5+j].creationTime);
                                                      }
                                                      ttAvr[i] = (int) ttAvr[i] / 5;
                                                    }

                                                    int cbtAvr[5];
                                                    for (int i = 0 ; i < 5 ; i++){
                                                      cbtAvr[i] = 0;
                                                      for (int j = 0 ; j < 5 ; j++){
                                                        cbtAvr[i] += (t[i*5+j].runningTime);
                                                      }
                                                      cbtAvr[i] = (int) cbtAvr[i] / 5;
                                                    }

                                                    int wAvr[5];
                                                    for (int i = 0 ; i < 5 ; i++){
                                                      wAvr[i] = 0;
                                                      for (int j = 0 ; j < 5 ; j++){
                                                        wAvr[i] += (t[i*5+j].terminationTime - t[i*5+j].creationTime - t[i*5+j].runningTime);
                                                      }
                                                      wAvr[i] = (int) wAvr[i] / 5;
                                                    }

                                                    for (int i = 0 ; i < 5 ; i++){
                                                      printf(1, "group with priority of %d : TT -> %d, cbt -> %d, WT -> %d \n", (i+1), ttAvr[i], cbtAvr[i], wAvr[i] );
                                                    }

                                                    printf(1,"-----------------------------------------------------------------------\ntotal average \n");
                                                    int TttAvr = (int) (ttAvr[0] + ttAvr[1] + ttAvr[2] + ttAvr[3] + ttAvr[4]) / 5;
                                                    int TcbtAvr = (int) (cbtAvr[0] + cbtAvr[1] + cbtAvr[2] + cbtAvr[3] + cbtAvr[4]) / 5;
                                                    int TwAvr = (int) (wAvr[0] + wAvr[1] + wAvr[2] + wAvr[3] + wAvr[4]) / 5;
                                                    printf(1, "total average : TT -> %d, cbt -> %d, WT -> %d \n", TttAvr, TcbtAvr, TwAvr );

                                                  }
                                                  else{
                                                    changePriority(1);
                                                    for (int i = 0; i < 500; i++) {
                                                      printf(1,"25 : %d\n", i);
                                                    }
                                                  }
                                                }
                                                else{
                                                  changePriority(1);
                                                  for (int i = 0; i < 500; i++) {
                                                    printf(1,"24 : %d\n", i);
                                                  }
                                                }
                                              }
                                              else{
                                                changePriority(1);
                                                for (int i = 0; i < 500; i++) {
                                                  printf(1,"23 : %d\n", i);
                                                }
                                              }
                                            }
                                            else{
                                              changePriority(1);
                                              for (int i = 0; i < 500; i++) {
                                                printf(1,"22 : %d\n", i);
                                              }
                                            }
                                          }
                                          else{
                                            changePriority(1);
                                            for (int i = 0; i < 500; i++) {
                                              printf(1,"21 : %d\n", i);
                                            }
                                          }
                                        }
                                        else{
                                          changePriority(2);
                                          for (int i = 0; i < 500; i++) {
                                            printf(1,"20 : %d\n", i);
                                          }
                                        }
                                      }
                                      else{
                                        changePriority(2);
                                        for (int i = 0; i < 500; i++) {
                                          printf(1,"19 : %d\n", i);
                                        }
                                      }
                                    }
                                    else{
                                      changePriority(2);
                                      for (int i = 0; i < 500; i++) {
                                        printf(1,"18 : %d\n", i);
                                      }
                                    }
                                  }
                                  else{
                                    changePriority(2);
                                    for (int i = 0; i < 500; i++) {
                                      printf(1,"17 : %d\n", i);
                                    }
                                  }
                                }
                                else{
                                  changePriority(2);
                                  for (int i = 0; i < 500; i++) {
                                    printf(1,"16 : %d\n", i);
                                  }
                                }
                              }
                              else{
                                changePriority(3);
                                for (int i = 0; i < 500; i++) {
                                  printf(1,"15 : %d\n", i);
                                }
                              }
                            }
                            else{
                              changePriority(3);
                              for (int i = 0; i < 500; i++) {
                                printf(1,"14 : %d\n", i);
                              }
                            }
                          }
                          else{
                            changePriority(3);
                            for (int i = 0; i < 500; i++) {
                              printf(1,"13 : %d\n", i);
                            }
                          }
                        }
                        else{
                          changePriority(3);
                          for (int i = 0; i < 500; i++) {
                            printf(1,"12 : %d\n", i);
                          }
                        }
                      }
                      else{
                        changePriority(3);
                        for (int i = 0; i < 500; i++) {
                          printf(1,"11 : %d\n", i);
                        }
                      }
                    }
                    else{
                      changePriority(4);
                      for (int i = 0; i < 500; i++) {
                        printf(1,"10 : %d\n", i);
                      }
                    }
                  }
                  else{
                    changePriority(4);
                    for (int i = 0; i < 500; i++) {
                      printf(1,"9 : %d\n", i);
                    }
                  }
                }
                else{
                  changePriority(4);
                  for (int i = 0; i < 500; i++) {
                    printf(1,"8 : %d\n", i);
                  }
                }
              }
              else{
                changePriority(4);
                for (int i = 0; i < 500; i++) {
                  printf(1,"7 : %d\n", i);
                }
              }
            }
            else{
              changePriority(4);
              for (int i = 0; i < 500; i++) {
                printf(1,"6 : %d\n", i);
              }
            }
          }
          else{
            changePriority(5);
            for (int i = 0; i < 500; i++) {
              printf(1,"5 : %d\n", i);
            }
          }
        }
        else{
          changePriority(5);
          for (int i = 0; i < 500; i++) {
            printf(1,"4 : %d\n", i);
          }
        }
      }
      else{
        changePriority(5);
        for (int i = 0; i < 500; i++) {
          printf(1,"3 : %d\n", i);
        }
      }
    }
    else{
      changePriority(5);
      for (int i = 0; i < 500; i++) {
        printf(1,"2 : %d\n", i);
      }
    }

  }
  else{
    changePriority(5);
    for (int i = 0; i < 500; i++) {
      printf(1,"1 : %d\n", i);
    }
  }
  exit();
}
