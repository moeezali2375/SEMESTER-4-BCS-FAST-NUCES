#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
int main(int argc, char *argv[])
{
    int pipe1[2]; //! p->c1
    int pipe2[2]; //! c1->c2
    int pipe3[2]; //! c2->p

    if (pipe(pipe1) == -1)
    {
        printf("Error creating pipe!\n");
        return 1;
    }
    if (pipe(pipe2) == -1)
    {
        printf("Error creating pipe!\n");
        return 1;
    }
    if (pipe(pipe3) == -1)
    {
        printf("Error creating pipe!\n");
        return 1;
    }
    pid_t pid = fork();
    if (pid == -1)
    {
        printf("Failed to create process!\n");
        return -1;
    }
    else if (pid)
    {
        //! PARENT_PROCESS
        printf("Welcome to the parent process!\n");
        int num = atoi(argv[1]);
        if (write(pipe1[1], &num, sizeof(int)) == -1)
        {
            printf("Failed to write the data from parent to child1!\n");
            return 2;
        }
        printf("Data: %d,successfully written from parent to child1\n", num);
        wait(NULL);
        pid = fork();
        if (!pid)
        {
            //! 2CHILD_PROCESS
            printf("Welcome to child 3!\n");
            int num;
            printf("Reading data from pipe 3!\n");
            if (read(pipe2[0], &num, sizeof(num)) == -1)
            {
                printf("Error while reading data from pipe2!\n");
                return 5;
            }
            printf("The data from pipe2 is: %d!\n", num);
            int square = num * num;
            printf("Calculating Square: %d!\n", square);
            printf("Now writing data back to pipe3!\n");
            if (write(pipe3[1], &square, sizeof(square)) == -1)
            {
                printf("Error while writing data to pipe3!\n");
                return 5;
            }
            printf("Data successfully written back to pipe3!\n");
        }
        else
        {
            wait(NULL); // HELP Wait for the 2nd child to be executed first!
            printf("Welcome back to the original process!\n");
            printf("Reading the final answer from pipe3!\n");
            if (read(pipe3[0], &num, sizeof(num)) == -1)
            {
                printf("Failed to read data from pipe3!\n");
                return 2;
            }
            printf("The final answer is: %d\n", num);
        }
    }
    else if (!pid)
    {
        //! 1CHILD_PROCESS
        printf("Welcome to the first child process!\n");
        int num;
        printf("Reading data from the pipe1!\n");
        if (read(pipe1[0], &num, sizeof(int)) == -1)
        {
            printf("Failed to read the data from parent to child1!\n");
            return 3;
        }
        printf("Data read from child1: %d\n", num);
        // HELP Now calculating factorial;
        int factorial = 1;
        while (num >= 2)
        {
            factorial *= num--;
        }
        printf("The factorial of the number is: %d!\n", factorial);
        // HELP Writing data to pipe2
        printf("Writing data from child1 to child2!\n");
        if (write(pipe2[1], &factorial, sizeof(factorial)) == -1)
        {
            printf("Failed to read the data from parent to child1!\n");
            return 3;
        }
    }
}