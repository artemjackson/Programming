#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    /** to do it more fun */
    srand(getpid());

    pid_t childPid;
    childPid = fork();

    sleep((rand()%10)/10.0);
    printf("Where I am?!\n");
    sleep((rand()%10)/10.0);

    if(childPid != 0 ){
        sleep((rand()%10)/10.0);
        /** getpid returns id of current procces */
        printf("It's parent process and it's nubmer is %d\n", (int)getpid() );
        printf("And it's child process id is %d\n", (int)childPid );
    }else {
        sleep((rand()%10)/10.0);
        printf("It's child process and it's nubmer is %d\n", (int)getpid() );
        /** getppid returns id of parent of current procces */
        printf("And it's parent process id is %d\n", (int)getppid() );
    }

    /**
     *  system call to weiv <user> directiry
     */
    /*  int returnValue;
        returnValue = system("ls -l ~/");
        printf("%d", returnValue);
    */
    return 0;
}
