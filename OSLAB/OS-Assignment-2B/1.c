#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t a = fork();
    if (a)
    {
        printf("I am parent my ID is=%d and my child ID is=%d\n", getpid(), a);
        wait(NULL);
    }
    else if (!a)
    {
        printf("I am Child my ID is=%d and my parent ID is=%d\n", getpid(), getppid());
    }
}