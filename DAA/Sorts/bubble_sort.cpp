#include <iostream>
using namespace std;
void bubble_sort(int array[], int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (array[j] > array[j + 1])
                swap(array[j], array[j + 1]);
        }
        size--;
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

    bubble_sort(array, size);

    cout << "After sorting: ";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}