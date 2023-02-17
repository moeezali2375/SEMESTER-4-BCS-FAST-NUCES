
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
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
void insertion_sort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j >= 0; j--)
        {
            if (array[j] < array[j - 1])
            {
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        }
    }
}
int main(int argc, char *argv[])
{
    pid_t a = fork();
    if (a > 0)
    {
        printf("Welcome to the parent process!\n");
        wait(NULL);
    }
    else if (a == 0)
    {
        printf("Welcome to the child process with PID: %d!\n", a);
        printf("Array Size: %d\n", argc);
        int array[1000];
        int k = 0;
        for (int i = 1; i < argc; i++)
        {
            array[k] = to_int(argv[i]);
            printf("%d\n", array[k]);
            k++;
        }
        insertion_sort(array, k);
        printf("Sorted array is: \n");
        for (int i = 0; i < k; i++)
        {
            printf("%d\n", array[i]);
        }
    }
}