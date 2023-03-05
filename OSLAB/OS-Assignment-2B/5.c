#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
int main(int argc, char *argv[])
{
    pid_t pid;
    switch (pid = fork())
    {
    case 0:
        printf("Child process created successfully with pid=%d!\n", getpid());
        break;
    default:
        wait(NULL);
        printf("We are in parent process with ID=%d and child's ID=%d!\n", getpid(), pid);
        break;
    case -1:
        printf("Failed to create child process!\n");
        perror("Fork");
        exit(1);
        break;
    }
}