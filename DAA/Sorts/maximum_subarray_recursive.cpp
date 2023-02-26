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
int MAX = INT_MIN;
int maximum_subarray(int array[], int start, int mid, int end)
{
    int sum;
    // MAX_LEFT_SUM
    sum = 0;
    int i = mid;
    int max_left = INT_MIN;
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
    int max_right = INT_MIN;
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

void function1(int array[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        function1(array, start, mid);
        function1(array, mid + 1, end);
        int new_max = maximum_subarray(array, start, mid, end);
        if (new_max > MAX)
            MAX = new_max;
    }
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
    function1(array, start, size - 1);
    cout << "MAX SUM IS: " << MAX << endl;
}