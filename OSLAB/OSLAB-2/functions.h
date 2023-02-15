#include <stdlib.h>

void sort(int array[], int size, bool order)
{
    if (order)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j >= 0; j--)
            {
                if (array[j] < array[j - 1])
                    swap(array[j], array[j - 1]);
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
                    swap(array[j], array[j - 1]);
            }
        }
    }
}
void findHighest(int array[], int size, int nth)
{
    sort(array, size, 0);
    printf("The %dth highest value in the array is: %d", nth, array[nth]);
}
void print(int array[], int size)
{
    printf("Array Elements: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}