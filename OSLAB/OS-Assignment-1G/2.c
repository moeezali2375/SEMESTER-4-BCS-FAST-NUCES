#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

    int pipe1[2];
    int pipe2[2];
    int number = atoi(argv[1]);

    pipe(pipe1);
    pipe(pipe2);

    // HELP sending number to pipe2
    if (write(pipe2[1], &number, sizeof(number)) == -1)
        printf("write error\n");

    //! LOOP
    while (number != 1)
    {
        read(pipe2[0], &number, sizeof(number));
        if (number == 1)
        {
            exit(EXIT_SUCCESS);
            return 0;
            break;
        }
        else
        {
            write(pipe1[1], &number, sizeof(number));
            pid_t pid = fork();
            if (pid)
            {
                wait(NULL);
            }
            else if (!pid)
            {
                int temp;
                read(pipe1[0], &temp, sizeof(temp));
                if (temp % 2 == 0)
                {
                    //! Even
                    temp = temp / 2;
                }
                else
                {
                    //! Odd
                    temp = 3 * temp;
                    temp++;
                }
                printf("%d\n", temp);
                write(pipe2[1], &temp, sizeof(temp));
            }
        }
    }
}