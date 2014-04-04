#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


int main()
{
    /**
     *  0 - stdin ;
     *  1 -stdout;
     *  2 -stderr
     */
    //  /** writing "Hello Worl!"
    //  char *hello = "Hello world!";
    //  write(1, hello , 12);

    //  /** reading any 3 sybols from keyboard ( '4' is writed because the are 3 symbols and key Enter is the fourth symbol)*/
    //  char input[3];
    //  read(0, input , 4);
    //  write(1, input , 3);

    //  /** reding random nuber from /dev/random */
    //  int number;
    //  /** desc - descriptor   */
    //  int desc = open("/dev/random", O_RDONLY);
    //  read(desc, &number, sizeof(int));
    //  printf("%d", number);

    //  /** fd - file discriptor */
    //  /** fd[0] - reading end , fd[1] - reading end */
    //  int fd[2];
    //  pipe(fd);
    //  char *hello = "Hello world!";
    //  char answer[20] = {0};

    //  /** Writing hello world to the fd[1]
    //   *  and reading it from fd[0] to answer
    //   *  pipe fd - works like queue, so
    //   *  we write 'hello' to fd[1]
    //   *  and read it form fd[0]
    //   *  like in queeu
    //   */
    //  write(fd[1], hello, 12);
    //  read(fd[0], answer, 12);
    //  write(1, answer, 12);

    /** xz vashe... */
    int fd[2];
    pid_t childPid;
    pipe(fd);
    childPid = fork();

    /** childPit > 0 means thet we in Parent */
    if(childPid > 0)
    {
        {
            /** It's a POSIX standart */
            close(fd[0]);
            char c;
            do
            {
                read(0, &c, 1);
                write(fd[1], &c, 1);
            } while(c != '\xA');       // '\xA' - 'Enter'
        }
        close(fd[1]);
    }
    else    // We in child
    {
        close(fd[1]);
        char c; int done = 0;
        do
        {
            read(fd[0], &c, 1);
            if(c == '\xA')
                done = 1;
            else c++;       // or any other function that changed symbol 'c'
            write(1, &c, 1);
        }  while(!done);
        close(fd[0]);
    }

    /** exec :
    * 'p' - uses variable of environment 'path'
    * 'v' - uses list of srtings
    * 'l' - uncountable number of arguments
    */


    return 0;
}
