#include <stdio.h>
#include <string.h>
void reverse_string(char str[])
{
    int start = 0;
    int end = strlen(str) - 1;
    while (start <= end)
    {
        char c = str[start];
        str[start] = str[end];
        str[end] = c;
        start++;
        end--;
    }
}
int main()
{
    char str[100];
    scanf("%[^\n]", str);
    reverse_string(str);
    printf("%s", str);
    return 0;
}