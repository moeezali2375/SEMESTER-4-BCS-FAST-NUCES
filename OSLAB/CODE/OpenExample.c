#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main ()
{
int fd = open("my.txt", O_RDONLY);
printf("%d\n", fd);
}
