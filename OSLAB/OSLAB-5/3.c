#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int pipe1[2];
    if (pipe(pipe1) == -1)
    {
        printf("Error creating pipe!\n");
    }
    pid_t pid = fork();
    if (pid)
    {
        //! PARENT
        FILE *reading = fopen(argv[1], "r");
        char array[1000];
        fgets(array, sizeof(array), reading);
        printf("The size of the data is: %lu\n", strlen(array));
        printf("The data read is: %s\n", array);
        close(pipe1[0]);
        if (write(pipe1[1], array, sizeof(array)) == -1)
            return 1;
        wait(NULL);
    }
    else if (!pid)
    {
        //! CHILD
        FILE *writing = fopen(argv[2], "w");
        char array[1000];
        close(pipe1[1]);
        if (read(pipe1[0], array, sizeof(array)) == -1)
            return 1;
        printf("Size: %lu!\n", strlen(array));
        printf("Content received is: %s\n", array);
        fputs(array, writing);
    }
}