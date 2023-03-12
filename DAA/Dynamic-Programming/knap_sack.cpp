#include <iostream>
using namespace std;
int search(int key, int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == key)
            return 1;
    }
    return 0;
}
void knap_sack_table(int weights[], int profits[], int size, int capacity)
{
    int **table = new int *[size + 1];
    for (int i = 0; i < size + 1; i++)
    {
        table[i] = new int[capacity + 1];
        for (int j = 0; j < capacity + 1; cout << table[i][j++] << " ")
        {
            if (i == 0)
            {
                table[i][j] = 0;
                continue;
            }
            if (j == 0)
            {
                table[i][j] = 0;
                continue;
            }
            if (weights[i - 1] <= j)
            {
                if (profits[i - 1] + table[i - 1][j - weights[i - 1]] > table[i - 1][j])
                {
                    table[i][j] = profits[i - 1] + table[i - 1][j - weights[i - 1]];
                }
                else
                {
                    table[i][j] = table[i - 1][j];
                }
            }
            else
                table[i][j] = table[i - 1][j];
        }
        cout << endl;
    }
    int *temp = new int[size];
    for (int i = 0; i < size; i++)
    {
        temp[i] = 0;
    }
    int max = table[size][capacity];
    int row = size;
    while (row >= 1)
    {
        while (search(max, table[row], capacity + 1) == 1)
        {
            row--;
        }
        row++;
        temp[row - 1] = 1;
        max -= profits[row - 1];
        if (max == 0)
        {
            break;
        }
    }
    for (int i = 0; i < size; i++)
    {
        cout << temp[i] << " ";
    }
    cout << endl;
}
int main()
{
    int weights[] = {2, 3, 4, 5};
    int profits[] = {1, 2, 5, 6};
    int capacity = 8;
    int size = 4;
    knap_sack_table(weights, profits, size, capacity);
}