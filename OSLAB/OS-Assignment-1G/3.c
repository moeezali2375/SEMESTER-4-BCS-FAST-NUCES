#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
    struct timeval start, end;
    gettimeofday(&start, NULL);
    pid_t pid = fork();
    if (pid == 0)
    {
        execvp(argv[1], &argv[1]);
        printf("Failed to execute!\n");
        exit(1);
    }
    else if (pid)
    {
        wait(NULL);
        //! Child process exited here
        gettimeofday(&end, NULL);
        int micro_sec = end.tv_usec - start.tv_usec;
        int sec = end.tv_sec - start.tv_sec;
        if (micro_sec < 0)
        {
            sec--;
            micro_sec = micro_sec + 1000000;
        }
        printf("Time taken: %d.%d seconds!\n", sec, micro_sec);
    }
}