
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int h, m, s;
    int lh, lm, ls;
    int laps;
    laps = atoi(argv[1]);
    lh = atoi(argv[2]);
    lm = atoi(argv[3]);
    ls = atoi(argv[4]);
    pid_t a = fork();
    if (a)
    {
        //! PARENT
        time_t st, ft;
        time(&st);
        wait(NULL);
        time(&ft);
        int ts = difftime(ft, st);
        if (ts > 3600)
        {
            h = ts % 3600;
            int n = h * 3600;
            ts -= n;
            m = ts % 60;
            n = m * 60;
            s = m - ts;
        }
        else if (ts > 60)
        {
            h = 0;
            int n = 0;
            m = ts % 60;
            n = m * 60;
            s = m - ts;
        }
        else
        {
            h = 0;
            m = 0;
            s = ts;
        }
        printf("Total time is %d - %d - %d\n", h, m, s);
    }
    else if (!a)
    {
        h = 0;
        m = 0;
        s = 0;
        int i = 0;
        //! CHILD
        while (laps > 0)
        {
            sleep(1);
            s++;
            if (s == 60)
            {
                m++;
                s = 0;
                if (m == 60)
                {
                    m = 0;
                    h++;
                    if (h == 24)
                        h = 0;
                }
            }
            if (s == ls && m == lm && h == lh)
            {
                s = 0;
                h = 0;
                m = 0;
                printf("Lap number %d is complete\n", ++i);
                laps--;
            }
        }
    }
}