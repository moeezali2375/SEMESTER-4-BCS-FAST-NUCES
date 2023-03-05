#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int fd[2];
    if (pipe(fd) == -1)
    {
        printf("Error creating pipe!\n");
    }
    pid_t pid = fork();
    if (pid)
    {
        //! PARENT
        close(fd[0]);
        if (write(fd[1], argv[1], sizeof(argv[1])) == -1)
        {
            return 1;
        }
        printf("Data written to pipe is: %s\n", argv[1]);
        wait(NULL);
    }
    else if (!pid)
    {
        //! CHILD
        close(fd[1]);
        char array[1000];
        if (read(fd[0], array, sizeof(array)) == -1)
        {
            return 1;
        }
        printf("Data successfully read!\n");
        for (int i = 0; i < strlen(array); i++)
        {
            if (array[i] >= 'a' && array[i] <= 'z')
            {
                array[i] -= 32;
            }
            else
                array[i] += 32;
        }
        printf("Modified String: %s", array);
    }
}