#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
    // pid_t pid = fork();
    // execlp("mkdir", "mkdir", "demo_folder", NULL);
    execvp("touch", "file1.txt");
}