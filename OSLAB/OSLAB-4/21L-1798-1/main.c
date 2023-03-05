#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("We are in the main process with PID: %d\n", getpid());
    printf("Calling print info process...\n");
    execv("my_info", NULL);
}
