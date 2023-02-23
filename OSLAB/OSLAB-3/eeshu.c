#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
int main(int argc, char *argv[])
{
    FILE *f;
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("ERROR IN READING FILE!");
        return -1;
    }
    char arr[1000];
    fgets(arr, 1000, f);
    printf("PID of example.c = %d\n", getpid());
    pid_t p;
    p = fork();
    int count = 0;
    if (p == 0)
    {
        printf("We are in the child process\n");
        for (int i = 0; i < strlen(arr); i++)
        {
            if (arr[i] == ':' || arr[i] == ','|| arr[i] == '.' || arr[i] == ';' || arr[i] == '\'')
                count++;
        }
        printf("Special character count: %d\n", count);
        exit(0);
    }
    else if (p > 0)
    {
        printf("We are in the parent process");
        wait(NULL);
    }
    else
    {
        printf("There is an error while calling fork()");
    }
    return 0;
}
