#include <iostream>
using namespace std;
void selection_sort(int array[], int size)
{
    int size2 = size;
    for (int i = 0; i < size2; i++)
    {
        int maxIndex = 0;
        for (int j = 0; j < size; j++)
        {
            if (array[maxIndex] < array[j])
            {
                maxIndex = j;
            }
        }
        swap(array[size - 1], array[maxIndex]);
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

    selection_sort(array, size);

    cout << "After sorting: ";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}