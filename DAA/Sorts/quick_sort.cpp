#include <iostream>
using namespace std;
int quick_sort_pivot(int array[], int i, int j)
{
    int pivot = i;
    while (i < j)
    {
        do
        {
            i++;
        } while (array[i] < array[pivot]);
        do
        {
            j--;
        } while (array[j] > array[pivot]);
        if (i < j)
            swap(array[i], array[j]);
    }
    swap(array[pivot], array[j]);
    return j;
}
void quick_sort(int array[], int i, int j)
{
    if (i >= j)
        return;
    int pivot = quick_sort_pivot(array, i, j);
    quick_sort(array, i, pivot);
    quick_sort(array, pivot + 1, j);
}
int main()
{
    int array[] = {5, 2, 5, 100, 0, 50, 200};
    int size = 7;
    cout << "Original array is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    quick_sort(array, 0, size - 1);
    cout << "Sorted array is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}