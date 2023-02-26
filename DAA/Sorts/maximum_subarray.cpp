//==========================================================================================================================================================
//                                                                                                                                                          
//              #####   #####    ##   ##  ######  #####            #####   #####   #####     ####  #####             ####                                 
//              ##  ##  ##  ##   ##   ##    ##    ##               ##     ##   ##  ##  ##   ##     ##               #    #                                
//              #####   #####    ##   ##    ##    #####  ########  #####  ##   ##  #####    ##     #####  ########     ##                                 
//              ##  ##  ##  ##   ##   ##    ##    ##               ##     ##   ##  ##  ##   ##     ##                ##                                   
//              #####   ##   ##   #####     ##    #####            ##      #####   ##   ##   ####  #####            ######                                
//                                                                                                                                                          
//==========================================================================================================================================================
#include <iostream>
using namespace std;
int maximum_subarray(int array[], int size, int &start, int &end)
{
    int max_sum = INT16_MIN;
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += array[j];
            if (sum > max_sum)
            {
                max_sum = sum;
                start = i;
                end = j;
            }
        }
    }
    return max_sum;
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
    cout << "Maximum sum is: " << maximum_subarray(array, size, start, end) << "with start: " << start << " and end: " << end << endl;
}