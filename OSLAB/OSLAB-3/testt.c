#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
int main(int argc, char *argv[])
{

    pid_t a = fork();
    if (a > 0)
    {
        printf("Parent process with id: %d\n", getpid());
        pid_t b = fork();
        if (!b)
        {
            printf("Child1 %d %d\n", getpid(), getppid());
            printf("The array is: \n%s\n", argv[1]);
            printf("The size of the array is: %d\n", strlen(argv[1]));
            execlp("33", "33", argv[1], NULL);
        }
        wait(NULL);
    }
    else if (!a)
    {
        printf("Child2: %d %d\n", getpid(), getppid());
    }
}