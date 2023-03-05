#include <iostream>
using namespace std;

int combine(int array[], int low, int high, int mid)
{
    int total_inversions = 0;
    int *temp = new int[high + 1];
    int i = low;
    int j = mid + 1;
    int k = low;
    int n = mid - low + 1;
    while (i <= mid && j <= high)
    {
        if (array[i] < array[j])
            temp[k++] = array[i++];
        else
        {
            total_inversions += (n - i);
            temp[k++] = array[j++];
        }
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
    return total_inversions;
}

int merge(int array[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        int total_inversions = 0;
        total_inversions += merge(array, low, mid);
        total_inversions += merge(array, mid + 1, high);
        total_inversions += combine(array, low, high, mid);
        return total_inversions;
    }
    return 0;
}

int inversions(int array[], int low, int high)
{
    int total_inversions = merge(array, low, high);
    for (int i = 0; i <= high; i++)
        cout << array[i] << " ";
    cout << endl;
    return total_inversions;
}
int main()
{
    int array[] = {9, 5, 100, 2, 0};
    // int array[] = {2, 4, 1, 3, 5};
    // int array[] = {3, 2, 1};
    // int array[] = {3, 5,6,9,1,2,7,8};
    int size = 5;

    cout << "Array: ";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
    cout << "Total Inversions are: " << inversions(array, 0, size - 1);
}