
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
int main()
{

    pid_t a = fork();
    if (a > 0)
    {
        printf("Original process: %d\n", getpid());
        wait(NULL);
    }
    else if (!a)
    {
        printf("Welcome to the child from 1st fork!\n");
        pid_t b = fork();
        if (b)
        {
            // wait(NULL);
            printf("Parent from 2nd fork! %d %d\n", getpid(), getppid());
            //! HELPPPPPPPP
        }
        else if (!b)
        {
            printf("Welcome to 3rd fork! %d\n",getpid());
            pid_t c = fork();
            if (c)
            {
                // wait(NULL);
                printf("Parent from 3rd fork! %d %d\n", getpid(), getppid());
                //! HELPPPPPPPP
            }
        }
    }
}