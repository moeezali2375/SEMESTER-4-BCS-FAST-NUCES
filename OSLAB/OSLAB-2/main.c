#include <stdio.h>
#include <string.h>
#include <math.h>

// #include <stdbool.h>
// #include "functions.c"
#include "header.h"
int to_int(char *str)
{
    int answer = 0;
    for (int i = strlen(str) - 1; i >= 0; i--)
    {
        int multiplier = pow(10, strlen(str) - 1 - i);
        int number = multiplier * ((int)str[i] - 48);
        answer += number;
    }
    // printf("%d", answer);
    return answer;
}
int main(int argc, char *argv[])
{
    int n_value = to_int(argv[argc - 1]);
    int order = to_int(argv[argc - 2]);
    //! storing the command line arguments to the array
    int array[1000];
    int k = 0;
    for (int i = 1; i < argc - 2; i++)
    {
        array[k++] = to_int(argv[i]);
    }
    int length = k;

    printf("Array Elements: ");
    print(array, length);
    printf("Sorted Elements are: ");
    sort(array, length, 1);
    print(array, length);
    // printf("The %dth highest element is: ", n_value);
    findhighest(array, length, n_value-1);
}