#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t pid = fork();
    if (!pid)
    {
        char *argv[] = {"fibonaci", "5", NULL};
        execv("fibonaci", argv);
    }
    else
    {
        wait(NULL);
    }
}
