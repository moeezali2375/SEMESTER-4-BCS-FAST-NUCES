#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <time.h>
int main(int argc, char *argv[])
{
    int i = 0;
    while (argv[1][i] != 0)
    {
        i++;
    }
    printf("Length of your name is: %d\n", i);
}