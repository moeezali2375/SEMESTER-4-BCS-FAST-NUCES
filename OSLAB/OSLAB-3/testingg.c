#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
int main()
{
    pid_t t;
    /* fork a child process */
    t = fork();
    if (t < 0)
    { /* error occurred */
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if (t == 0)
    { /* child process */
        execlp("/bin/ls", "ls", NULL);
    }
    else
    { /* parent process */
        /* parent will wait for the child to complete */ wait(NULL);
        printf("Child Complete");
    }
    return 0;
}