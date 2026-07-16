#include <stdio.h>
int my_strlen(char *str)
{
    int len = 0;
    for (int i = 0; i < 100; i++)
    {
        if (str[i] == '\0')
            break;
        len++;
    }
    return len;
}
int main()
{
    char str[100];
    scanf("%[^\n]", str);

    printf("%d", my_strlen(str));
    return 0;
}