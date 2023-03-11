#include <iostream>
#include <stdint.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;
int main()
{
    int num, factorial, square;
    int pipe1[2], pipe2[2], pipe3[2];
    pid_t pid1;
    cout << "Enter a number: ";
    cin >> num;
    if (pipe(pipe1) < 0 || pipe(pipe2) < 0||pipe(pipe3)<0)
    {
        cerr << "Error: Unable to create pipes\n";
        exit(1);
    }
    close(pipe1[0]);
    write(pipe1[0], &num, sizeof(num));
    pid1 = fork();
    if (pid1 < 0)
    {
        cerr << "Error: Unable to fork first child process\n";
        exit(1);
    }
    if (pid1 == 0)
    {
        //! Child1 process
        // close(pipe1[1]);
        read(pipe1[0], &num, sizeof(num));
        factorial = 1;
        for (int i = 1; i <= num; i++)
        {
            factorial *= i;
        }
        cout << "Factorial: " << factorial << endl;
        close(pipe2[0]);
        write(pipe2[1], &factorial, sizeof(factorial));
        exit(0);
    }
    else if (pid1)
    {
        wait(NULL);
        pid1 = fork(); // Forking again
        if (pid1 == 0)
        {
            close(pipe2[1]);
            read(pipe2[0], &num, sizeof(num));
            square = num * num;
            cout << "Square is: "<<square<<endl;
            write(pipe3[1], &square, sizeof(square));
            exit(0);
        }
        else if (pid1)
        {
            wait(NULL);
            int temp;
            close(pipe3[1]);
            read(pipe3[0], &temp, sizeof(temp));
            cout<<"Data read in the last parent process: "<<temp<<endl;
        
        }
    }
}