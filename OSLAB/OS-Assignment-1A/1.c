#include <stdio.h>
int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Error opening input file!\n");
        return 1;
    }
    else
    {
        char c;
        int total_digits = 0;
        while ((c = getc(fp)) != EOF)
        {
            if (c >= '0' && c <= '9')
            {
                total_digits++;
            }
        }
        fclose(fp);
        printf("Total Number of Digits are: %d\n", total_digits);
    }
}