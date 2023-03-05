#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t pid = fork();
    if (!pid)
    {
        printf("Created a demo folder!\n");
        execlp("mkdir", "mkdir", "demo_folder", NULL);
    }
    else if (pid)
    {
        wait(NULL);
        pid = fork();
        if (!pid)
        {
            char *argument_list[] = {"touch", "demo_folder/1.txt", "demo_folder/2.txt", NULL};
            execvp("touch", argument_list);
            printf("Created a demo files!\n");
        }
        else
        {
            wait(NULL);
            pid = fork();
            if (!pid)
            {
                printf("Listing files...\n");
                char *args[] = {"ls", "demo_folder", NULL};
                execvp("ls", args);
            }
            else
            {
                wait(NULL);
                printf("Removing files in...!\n");
                for (int i = 10; i >= 1; i--)
                {
                    sleep(1);
                    printf("%d!\n", i);
                }
                char *args[] = {"rm", "-rf", "demo_folder", NULL};
                execvp("rm", args);
            }
        }
    }
}