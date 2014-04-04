#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

/*
int main()
{
    int a = 6;
    pid_t child;
    child = fork();

    if(child)   //  if child != 0 so it's parent process else it's a child process
    {
        sleep(1);
        printf("It's a parent process: a = %d, &a = %p \n", a , &a);
    }else
    {
        a += a;
        printf("It's a child process: a = %d, &a = %p \n", a , &a);
    }

    return 0;
}
*/

/*
int main()
{
    pid_t result = fork();
    if(result == 0)  //  if result == 0 so it's child process else it's a parent process
    {
        printf("ls is started\n");
        execlp("ls", "ls", "/", NULL);
        //  if you on GNOME you can uncomment follow line to start Gedit
        //  execlp("gedit", "gedit", NULL);
        printf("Error! Not valid comamnd\n");
    }
    //  now it's a parent process
    wait(NULL); //  wait while child process will finished
    printf("It's a parent process\n");

    return 0;
}
*/


int main(int argc, char **argv)
{
    pid_t status, child_pid;
    int exit_status;

    if(argc < 2)
    {
        fprintf(stderr, "Too few arguments\n");
        return 1;
    }

    status = fork();

    if(status == -1)
    {
        fprintf(stderr, "Fork error\n");
    }

    if(status == 0)     // It's a child process
    {
        execlp("ls", "ls", argv[1], NULL);
        fprintf(stderr,"Exec error\n");
        return 1;
    }

    child_pid = wait(&exit_status);

    if(WIFEXITED(exit_status))
    {
        printf("Process with PID = %d has exited with code = %d\n", child_pid, WEXITSTATUS(exit_status));
    }

    return 0;
}

