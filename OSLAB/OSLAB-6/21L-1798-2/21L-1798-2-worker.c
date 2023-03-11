#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>

int calculate(int op, int op1, int op2)
{
    if (op == '+')
    {
        return op1 + op2;
    }
    if (op == '-')
    {
        return op1 - op2;
    }
    if (op == '*')
    {
        return op1 * op2;
    }
    if (op == '/')
    {
        return op1 / op2;
    }
    return 0;
}
int main(int argc, char *argv[])
{
    int array[3];
    char *pipe_name = (argv[1]);
    int fd = open(pipe_name, O_RDWR);
    read(fd, array, sizeof(array));
    int operand = array[0];
    int operand1 = array[1];
    int operand2 = array[2];
    int result = calculate(operand, operand1, operand2);
    write(fd, &result, sizeof(result));
    close(fd);
}