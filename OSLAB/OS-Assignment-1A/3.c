#include <stdio.h>
#include <string.h>

int word_separator(char word[][1024], char array[])
{
    int k = 0;
    int word_number = 0;
    int word_iterator = 0;
    for (int i = 0; i < 1024; i++)
    {
        if (array[i] == ' ')
        {
            int j = k;
            for (j = k, word_iterator = 0; j < i; j++, word_iterator++)
            {
                word[word_number][word_iterator] = array[j];
            }
            k = j + 1;
            word_number++;
        }
    }
    return word_number - 1;
}

void swapper(char word[][1024], int word_count)
{
    for (int I = 0; I < word_count; I++)
    {
        int length = strlen(word[I]);
        for (int i = 0, j = length - 1; i < j; i++, j--)
        {
            if (word[I][i] != 'a' && word[I][i] != 'e' && word[I][i] != 'i' && word[I][i] != 'o' && word[I][i] != 'u' && word[I][j] != 'a' && word[I][j] != 'e' && word[I][j] != 'i' && word[I][j] != 'o' && word[I][j] != 'u' && word[I][i] != 'A' && word[I][i] != 'E' && word[I][i] != 'I' && word[I][i] != 'O' && word[I][i] != 'U' && word[I][j] != 'A' && word[I][j] != 'E' && word[I][j] != 'I' && word[I][j] != 'O' && word[I][j] != 'U')
            {
                char temp = word[I][j];
                word[I][j] = word[I][i];
                word[I][i] = temp;
            }
            else
            {
                if (word[I][i] == 'a' || word[I][i] == 'e' || word[I][i] == 'i' || word[I][i] == 'o' || word[I][i] == 'u' || word[I][i] == 'A' || word[I][i] == 'E' || word[I][i] == 'I' || word[I][i] == 'O' || word[I][i] == 'U')
                {
                    j++;
                }
                else
                {
                    i--;
                }
            }
        }
    }
}
int main(int argc, char *argv[])
{
    FILE *fptr;
    fptr = fopen(argv[1], "r");
    //! read the file
    char array[1024];
    fgets(array, sizeof(array), fptr);
    printf("%s\n", array);
    //! Separating words
    char words[1024][1024];
    int word_count = word_separator(words, array);
    // printf("%d\n", word_count);
    //! Calling swapper
    swapper(words, word_count);
    for (int i = 0; i < word_count; i++)
    {
        printf("%s\n", words[i]);
    }
}