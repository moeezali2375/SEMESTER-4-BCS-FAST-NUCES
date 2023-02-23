#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <time.h>
int search_backward(int array[][5], int key, int i, int j)
{
    while (i >= 0)
    {
        if (j < 0)
        {
            j = 4;
            i--;
            if (i < 0)
                return 1;
        }
        if (array[i][j] == key)
            return 0;
        else
            j--;
    }
    return 1;
}
int main()
{
    // FILLING WITH RANDOM DATA
    int array[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            array[i][j] = (rand() % (1000 - 1 + 1)) + 1;
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    pid_t a = fork();
    if (a > 0)
    {
        //! PARENT_PROCESS
        wait(NULL);
        int lower_sum = 0;
        int upper_sum = 0;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (j >= i)
                    upper_sum += array[i][j];
                if (j <= i)
                    lower_sum += array[i][j];
            }
        }
        printf("The upper sum is: %d\n", upper_sum);
        printf("The lower sum is: %d\n", lower_sum);
    }
    else if (!a)
    {
        printf("Child: %d\n", getpid());
        printf("Parent: %d\n", getppid());
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                int row = i;
                int col = j;
                if (search_backward(array, array[i][j], row, col - 1))
                {
                    int frequency = 0;
                    while (row < 5)
                    {
                        if (array[i][j] == array[row][col])
                            frequency++;
                        col++;
                        if (col >= 5)
                        {
                            col = 0;
                            row++;
                        }
                    }
                    printf("Frequency of %d is: %d\n", array[i][j], frequency);
                }
            }
        }
    }
}