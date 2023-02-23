#include <stdio.h>
#include <unistd.h>
int main()
{
    printf("We are in main!\n");
    execv("2", NULL);
}
