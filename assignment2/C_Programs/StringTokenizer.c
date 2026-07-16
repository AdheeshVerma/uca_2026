#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
    char str[100];
    scanf("%[^\n]", str);
    char *token = strtok(str, ",");
    while (token)
    {
        printf("%s\n", token);
        token = strtok(NULL, ",");
        // dont need to increment token, strtok uses a static point internally and null asks it to resume where it left off
    }
    return 0;
}