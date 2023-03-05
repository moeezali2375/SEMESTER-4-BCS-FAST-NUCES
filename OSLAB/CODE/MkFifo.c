#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
int x;
x = mkfifo("fifo", 0777);
printf("A named pipe created");
return 0;
}
