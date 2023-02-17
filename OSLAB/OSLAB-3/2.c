
#include <stdio.h>
#include <stdlib.h>
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
void insertion_sort_down(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j >= 0; j--)
        {
            if (array[j] > array[j - 1])
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
        wait(NULL);
        pid_t b = fork();
        // printf("Welcome to the parent process!\n");
        wait(NULL);
        if (b == 0)
        {
            printf("\nI am child 2 with PID: %d and parent's ID=%d!\n", getpid(), getppid());
            int array[1000];
            int k = 0;
            for (int i = 1; i < argc; i++)
            {
                array[k] = to_int(argv[i]);
                // printf("%d\n", array[k]);
                k++;
            }
            insertion_sort_down(array, k);
            printf("Sorted array is: \n");
            for (int i = 0; i < k; i++)
            {
                printf("%d,", array[i]);
            }
            exit(0);
        }
    }
    else if (a == 0)
    {
        printf("I am child 1 with PID: %d and parent's ID=%d!\n", getpid(), getppid());
        int array[1000];
        int k = 0;
        for (int i = 1; i < argc; i++)
        {
            array[k] = to_int(argv[i]);
            // printf("%d,", array[k]);
            k++;
        }
        insertion_sort(array, k);
        printf("Sorted array is: \n");
        for (int i = 0; i < k; i++)
        {
            printf("%d,", array[i]);
        }
        exit(0);
    }
    printf("\nParent process terminating with pid %d and parent's ID=%d\n", a, getppid());
}