#include <stdio.h>

void url_encode(char *str, int len)
{
    int space_count = 0;

    for (int i = 0; i < len; i++)
    {
        if (str[i] == ' ')
            space_count++;
    }
    int index = len + (space_count * 2);
    str[index] = '\0';

    for (int i = len - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            str[index - 1] = '0';
            str[index - 2] = '2';
            str[index - 3] = '%';
            index -= 3;
        }
        else
        {
            str[index - 1] = str[i];
            index--;
        }
    }
}

int main()
{
    char str[100];
    int len;

    fgets(str, sizeof(str), stdin);
    scanf("%d", &len);
    url_encode(str, len);
    printf("Encoded string: %s\n", str);
    return 0;
}