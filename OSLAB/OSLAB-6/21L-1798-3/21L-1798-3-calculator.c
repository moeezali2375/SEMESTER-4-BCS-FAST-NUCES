#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int array[10];
    char *pipe_name = (argv[1]);
    int fd = open(pipe_name, O_RDWR);
    read(fd, array, sizeof(array));
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += array[i];
    }
    write(fd, &sum, sizeof(sum));
}