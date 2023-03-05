#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 1024

int main()
 {
   int fd[2];
   int rv = pipe(fd);
   int fs[2];
   rv = pipe(fs);
   pid_t cpid = fork();
   pid_t gcpid;
   if (cpid == 0)
    { 
     
      gcpid = fork();
     if (gcpid == 0)
      {
       close(1);
       dup(fs[1]);
       close(fs[0]);
       execlp("man","man","ls",NULL);
      }
     else
      {
       close(1);
       dup(fs[1]);
       close(fs[0]);
       execlp("grep","grep","ls",NULL);
       
      }
    }
   else
    {
     close(0);
     dup2(fd[0],fd[0]);
     close(fd[1]);
     wait(NULL);
     execlp("wc", "wc", "-l",NULL);
    }
   return 0;
 }
=