#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int n, i, t1 = 0, t2 = 1, nextTerm;
    n = atoi(argv[1]);
    printf("Fibonacci Series: ");
    for (i = 1; i <= n; ++i)
    {
        printf("%d, ", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    return 0;
}
