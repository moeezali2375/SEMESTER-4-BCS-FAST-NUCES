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
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char *pipe_name = (argv[1]);
    int fd = open(pipe_name, O_RDWR);
    write(fd, array, sizeof(array));
    sleep (1);
    int sum = 0;
    read(fd, &sum, sizeof(sum));
    printf("Sum of the array is: %d!\n", sum);
    close(fd);
}