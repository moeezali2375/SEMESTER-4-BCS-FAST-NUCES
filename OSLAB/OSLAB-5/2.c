#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
int main(int argc, char *argv[])
{
    int pipe1[2];
    int pipe2[2];
    if (pipe(pipe1) == -1)
    {
        printf("Error creating pipe!\n");
    }
    if (pipe(pipe2) == -1)
    {
        printf("Error creating pipe!\n");
    }
    pid_t pid = fork();
    if (pid)
    {
        //! PARENT
        int size;
        printf("Enter size of array: ");
        scanf("%d", &size);
        int array[1000];
        printf("Enter elements of array: \n");
        for (int i = 0; i < size; i++)
        {
            scanf("%d", &array[i]);
        }
        close(pipe1[0]);
        if (write(pipe1[1], array, sizeof(array)) == -1)
        {
            return 1;
        }
        wait(NULL);
        printf("Welcome back!\n");
        int sum;
        close(pipe2[1]);
        if (read(pipe2[0], &sum, sizeof(sum)) == -1)
            return 1;
        printf("Sum received from child: %d\n", sum);
    }
    else if (!pid)
    {
        //! CHILD
        close(pipe1[1]);
        int array[1000];
        if (read(pipe1[0], array, sizeof(array)) == -1)
        {
            return 1;
        }
        printf("Data successfully read!\n");
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += array[i];
        }
        close(pipe2[0]);
        if (write(pipe2[1], &sum, sizeof(sum)) == -1)
        {
            return 1;
        }
        printf("Data successfully written back to parent!\n");
    }
}