#include<stdio.h>
void sort(int array[], int size, int order)
{
    if (order)
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
    else
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
}
void findhighest(int array[], int size, int nth)
{
    sort(array, size, 0);
    printf("The %dth highest value in the array is: %d", nth, array[nth]);
}
void print(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}