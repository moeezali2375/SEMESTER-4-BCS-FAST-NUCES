//======================================================================================
//
//              ####    ##  ##   ##  ##  ####    #####
//              ##  ##  ##  ##   ##  ##  ##  ##  ##
//              ##  ##  ##  ##   ##  ##  ##  ##  #####
//              ##  ##  ##   ## ##   ##  ##  ##  ##
//              ####    ##    ###    ##  ####    #####
//
//======================================================================================

#include <iostream>
using namespace std;
int max_sum = INT_MIN;
int start_index = -1;
int end_index = -1;
int maximum_subarray(int array[], int start, int mid, int end)
{
    int sum;
    // MAX_LEFT_SUM
    sum = 0;
    int i = mid;
    int max_left = array[i];
    int max_left_start = i;
    int max_left_end = i;
    while (i >= start)
    {
        sum += array[i];
        if (sum > max_left)
        {
            max_left = sum;
            max_left_end = i;
        }
        i--;
    }
    // MAX_RIGHT_SUM
    sum = 0;
    i = mid + 1;
    int max_right = array[i];
    int max_right_start = i;
    int max_right_end = i;
    while (i <= end)
    {
        sum += array[i];
        if (sum > max_right)
        {
            max_right = sum;
            max_right_end = i;
        }
        i++;
    }
    // MAX_CROSSING_SUM
    int max_crossing = max_left + max_right;
    if (max_crossing > max_left && max_crossing > max_right)
        return max_crossing;
    if (max_left > max_right)
        return max_left;
    return max_right;
}

int function1(int array[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        function1(array, start, mid);
        function1(array, mid + 1, end);
        return maximum_subarray(array, start, mid, end);
    }
    return -1;
}
int main()
{
    int array[] = {-1, 2, 3, -4, 5, 10};
    int size = 6;
    cout << "Original array is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
    int start = 0;
    int end = 0;
    cout << "Maximum sum is: " << function1(array, start, size - 1);
}