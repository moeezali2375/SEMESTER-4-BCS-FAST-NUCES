#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void to_numbers_only(char array[], char *filename, int size)
{
    FILE *fp;
    fp = fopen(filename, "w");
    for (int i = 0; i < size; i++)
    {
        if (array[i] >= '0' && array[i] <= '9')
            fprintf(fp, "%c", array[i]);
    }
    fclose(fp);
}

int main(int argc, char *argv[])
{
    char *input = argv[1];
    char *output = argv[2];
    char *array;
    FILE *f;
    f = fopen(input, "r");
    int numbytes;
    // reads the size of the string from the input
    fseek(f, 0L, SEEK_END);
    numbytes = ftell(f);
    fseek(f, 0L, SEEK_SET);
    array = (char *)calloc(numbytes, sizeof(char)); // allocates enough memory for the string
    fread(array, sizeof(char), numbytes, f);
    to_numbers_only(array, output, numbytes);
    // printf("%s", array); //prints the string
}