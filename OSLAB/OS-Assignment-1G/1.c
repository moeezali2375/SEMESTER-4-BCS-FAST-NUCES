#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        sleep(1);
        printf(".\n");
    }
    printf("Custom shell loading.....!\n");
    sleep(1);
    printf("Welcome to the custom SHELL!\n");
    sleep(1);
    char array[100];
    system("clear");
    do
    {
        int parallel_flag = 0;
        printf("Enter the command to execute: ");
        fgets(array, sizeof(array), stdin);
        if (strchr(array, '&') != NULL)
        {
            parallel_flag = 1;
            strtok(array, "&");
        }
        array[strcspn(array, "\n")] = '\0';
        if (strcmp(array, "exit") == 0 || strcmp(array, "exit\n") == 0)
        {
            printf("Exiting!\n");
            exit(0);
        }
        else
        {
            //! EXECUTE OK
            char *argv[50];
            //! Separating the commands and the argv
            int num_arguments = 0;
            argv[num_arguments] = strtok(array, " ");
            while (argv[num_arguments] != NULL && num_arguments < 50)
            {
                num_arguments++;
                argv[num_arguments] = strtok(NULL, " ");
            }
            pid_t pid = fork();
            if (!pid)
            {
                if (execvp(argv[0], argv) == -1)
                    printf("Failed to execute!\n");
            }
            else
            {
                if (parallel_flag)
                    ;
                else
                    wait(NULL);
            }
        }
    } while (strcmp(array, "exit") != 0);
}
