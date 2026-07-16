#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char str[] = "This is to check if things do work out as they are supposed to be";
    char *token = strtok(str, " ");
    while (token)
    {
        printf("%s ,", token);
        token = strtok(NULL, " ");
        // dont need to increment token, strtok uses a static point internally and null asks it to resume where it left off
    }
    return 0;
}