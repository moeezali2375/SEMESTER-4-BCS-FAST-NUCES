#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
int main(int argc, char *argv[])
{
    FILE *f;
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("ERROR IN READING FILE!");
        return -1;
    }
    char arr[1000];
    fgets(arr, 1000, f);
    int count = 0;
    for (int i = 0; i < strlen(arr); i++)
    {
        if (arr[i] == argv[2][0])
        {
            int k = 0;
            int flag = 1;
            for (int j = i; k < strlen(argv[2]); j++, k++)
            {
                if (arr[j] != argv[2][k] || j >= strlen(arr))
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                count++;
        }
    }
    printf("Total occurences of the given string is: %d\n", count);
    return 0;
}
