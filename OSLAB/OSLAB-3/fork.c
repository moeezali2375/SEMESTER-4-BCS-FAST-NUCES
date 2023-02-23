#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
int main()
{

    int pid = 0;
    pid = fork();
    int x = 1;
    if (pid == 0)
    {
        printf("%d,", x);
        pid = fork();
        x++;
        if (pid == 0)
        {
            printf("%d,", x);
            x++;
            pid = fork();
            if (pid > 0)
            {
                x++;
                printf("%d,", x);
                pid = fork();
                if (pid > 0)
                {
                    printf("%d,", x);
                    pid = fork();
                    if (pid == 0)
                    {
                        x++;
                        printf("%d,", x);
                    }
                }
            }
        }
    }

    else if (pid > 0)
    {
        printf("%d,", x);
        return 0;
    }
} 