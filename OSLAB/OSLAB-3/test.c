int x = 10;
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    fork();
    if ((fork() || fork()) && fork())
    {
        fork();
    }
    printf("h!\n");
}