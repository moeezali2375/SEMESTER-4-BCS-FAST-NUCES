#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main()
{
int x,n;
char buffer[100];
x = open("fifo", O_RDONLY);
n = read(x, buffer, 100);
printf("Reader process having PID %d started\n", getpid());
printf("Data received by the receiver %d is %s\n", getpid(), buffer);
}
