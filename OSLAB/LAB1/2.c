#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
int main(int argc, char *argv[])
{
    int sum = 0;
    for (int I = 1; I < argc; I++)
    {
        char *temp_array = argv[I];
        int length = strlen(temp_array);

        for (int i = length - 1; i >= 0; i--)
        {
            int p = length - 1 - i;
            int p_value = 1;
            int temp_value = (int)temp_array[i] - 48;
            while (p > 0)
            {
                p_value *= 10;
                p--;
            }
            int new_value = temp_value * p_value;
            sum += new_value;
        }
    }
    printf("The SUM of the given numbers is: %d\n", sum);
    float average = (float)sum / (argc - 1);
    printf("The AVERAGE of the given number is: %f", average);
    printf("\n");
    return 0;
}