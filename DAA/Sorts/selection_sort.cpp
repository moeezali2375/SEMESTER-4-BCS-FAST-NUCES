#include <iostream>
using namespace std;
void selection_sort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] > array[maxIndex])
                maxIndex = j;
        }
        swap(array[i], array[maxIndex]);
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