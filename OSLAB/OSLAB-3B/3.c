#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
void remove_characters(char *array)
{
    int length = strlen(array);
    for (int i = 0; i < length; i++)
    {
        if ((array[i] >= 'a' && array[i] <= 'z') || (array[i] >= 'A' && array[i] <= 'Z'))
        {
            ;
        }
        else
        {
            for (int j = i; j < length - 1; j++)
            {
                array[j] = array[j + 1];
            }
            array[length - 1] = 0;
            length--;
            i--;
        }
    }
}
int main(int argc, char *argv[])
{

    pid_t a = fork();
    if (a > 0)
    {
        printf("Parent process with id: %d\n", getpid());
        pid_t b = fork();
        if (!b)
        {
            printf("Child1 %d %d\n", getpid(), getppid());
            printf("The array is: \n%s\n", argv[1]);
            printf("The size of the array is: %lu\n", strlen(argv[1]));
            // TODO exec functions to be corrected here
            // if (execvp("ls", NULL))
            ;
            // if (execl("/Users/moeezali/Documents/VS/SEMESTER#4/OSLAB/OSLAB-3B/33", argv[1]) < 0)
            // {
            // printf("error!\n");
            // }
            remove_characters(argv[1]);
            // TODO 2nd exec function to be corrected here
            printf("The updated array is: %s\n", argv[1]);
            printf("The length of array is: %lu\n", sizeof(argv[1]));
        }
        wait(NULL);
    }
    else if (!a)
    {
        printf("Child2: %d %d\n", getpid(), getppid());
    }
}