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
    printf("Enter a string: ");
    char array[500];
    scanf("%s", array);
    // printf("%s", array);

    char *pipe_name = (argv[1]);
    int fd = open(pipe_name, O_RDWR);
    write(fd, array, sizeof(array));
    sleep(2);
    read(fd, array, sizeof(array));
    printf("String from child is: %s!\n", array);
    close(fd);
}