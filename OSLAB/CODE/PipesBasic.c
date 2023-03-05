#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char * argv)
{


int fd[2];
if (pipe(fd) == -1)
	{
		printf("Error, while opening the pipe.");
	}

int pid  = fork();
if (pid == 0)
	{
		close(fd[0]);
		int x;
		printf("Enter a integer to send the parent process:  ");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	}
else if (pid > 0)
	{
		wait(NULL);
		close(fd[1]);
		int y;
		read(fd[0], &y, sizeof(int));
		printf("Data received from the child process is: %d\n", y);
		close(fd[0]);
	}

return 0;
}
