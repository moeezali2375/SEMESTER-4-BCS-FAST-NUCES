#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

void case_changer(char array[])
{
    for (int i = 0; i < strlen(array); i++)
    {
        if (array[i] >= 'a' && array[i] <= 'z')
        {
            array[i] -= 32;
        }
        else
            array[i] += 32;
    }
}
int main(int argc, char *argv[])
{
    char *pipe_name = (argv[1]);
    int fd = open(pipe_name, O_RDWR);
    char array[500];
    read(fd, array, sizeof(array));
    // printf("String from child is: %s!\n", array);
    case_changer(array);
    write(fd, array, sizeof(array));
    close(fd);
}