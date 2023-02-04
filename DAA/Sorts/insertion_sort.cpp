#include <iostream>
using namespace std;
void insertion_sort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (array[j - 1] > array[j])
                swap(array[j - 1], array[j]);
            else
                break;
        }
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

    insertion_sort(array, size);

    cout << "After sorting: ";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}