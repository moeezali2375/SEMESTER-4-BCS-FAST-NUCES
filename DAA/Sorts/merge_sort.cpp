#include <iostream>
using namespace std;

void combine(int array[], int low, int high, int mid)
{
    int *temp = new int[high + 1];
    int i = low;
    int j = mid + 1;
    int k = low;
    while (i <= mid && j <= high)
    {
        if (array[i] < array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
    }
    while (i <= mid)
        temp[k++] = array[i++];
    while (j <= high)
        temp[k++] = array[j++];
    for (int q = low; q < high + 1; q++)
    {
        array[q] = temp[q];
    }
    delete[] temp;
}

void merge(int array[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge(array, low, mid);
        merge(array, mid + 1, high);
        combine(array, low, high, mid);
    }
}

int main()
{
    int array[] = {9, 5, 100, 2, 0};
    int size = 5;

    cout << "Before sorting: ";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;

    merge(array, 0, 4);

    cout << "After sorting: ";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}