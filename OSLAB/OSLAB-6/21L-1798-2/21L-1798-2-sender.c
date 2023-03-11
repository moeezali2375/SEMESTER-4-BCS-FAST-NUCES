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
    int array[] = {'+', 4, 7};
    char *pipe_name = (argv[1]);
    int fd = open(pipe_name, O_RDWR);
    write(fd, array, sizeof(array));
    int result = 0;
    sleep(1);
    read(fd, &result, sizeof(result));
    printf("The result is: %d!\n", result);
    close(fd);
}