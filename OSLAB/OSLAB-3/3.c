
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
int to_int(char *str)
{
    int answer = 0;
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        int multiplier = pow(10, strlen(str) - 1 - i);
        int number = multiplier * ((int)str[i] - 48);
        answer += number;
    }
    // printf("%d", answer);
    return answer;
}
int main(int argc, char *argv[])
{
    int times = to_int(argv[1]);
    pid_t a = fork();
    for (int i = 0; i < times; i++)
    {
        if (a > 0)
        {
            wait(NULL);
        }
        else
        {
            a = fork();
            printf("My id%d and ppid is %d\n", getpid(), getppid());
        }
    }
}