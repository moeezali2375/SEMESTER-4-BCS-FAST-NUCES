#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
int x,n;
x = open("fifo",O_WRONLY);
write(x, "OS CLass FAST", 13);
printf("Sender process having PID %d sent the data\n" , getpid());
}
