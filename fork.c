#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    // fork();
    // printf("hello PID = %d\n",getpid());
    // // hello PID = 2503 for the parent process
    // // hello PID = 2507 for the child process, seperate process with diffferent process id
    //----------------------------------------------------------------------//
    
    fork();
    fork();
    fork();
    printf("hello PID\n = %d\n",getpid());
    // hello PID = 32544
    // hello PID = 32545
    // hello PID = 32547
    // hello PID = 32549
    // hello PID = 32548
    // hello PID = 32550
    // hello PID = 32546
    // hello PID = 32551
    // for each fork a new process will be created
    // for fork - p1 is created
    // for  fork1- p1->p2
    // for  fork2 - p1->p2
    //                 |   |
    //                 p3  p4
                    
    // for  fork3-  p5<-p1->p2->p6
    //                 |   |
    //             p8<-p3  p4->p7
}