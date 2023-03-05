#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
int main()
{
    pid_t pid = fork();
    if (pid)
    {
        //! PARENT
        int status;
        wait(&status);
        printf("Exit status: %d\n", status);
        exit(0);
    }
    else if (!pid)
    {
        //! CHILD
        int num;
        printf("Please enter a number: ");
        scanf("%d", &num);
        int factorial = 1;
        while (num >= 2)
        {
            factorial *= num;
            num--;
        }
        printf("Factorial of the number is: %d\n", factorial);
        exit(0);
    }
}