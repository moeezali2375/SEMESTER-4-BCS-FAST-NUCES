#include <stdio.h>
#include <string.h>

void tokenize(char *string, char *delimiter) {
    char *token;
    token = strtok(string, delimiter);
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, delimiter);
    }
}

int main() {
    char string[100] = "Hello world! How are you?";
    char delimiter[2] = " ";

    tokenize(string, delimiter);

    return 0;
}
