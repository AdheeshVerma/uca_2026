#include <stdio.h>

int find_substring(const char *haystack, const char *needle)
{
    if (*needle == '\0')
        return 0;
    for (int i = 0; haystack[i] != '\0'; i++)
    {
        int j = 0;
        while (haystack[i + j] != '\0' &&
               needle[j] != '\0' &&
               haystack[i + j] == needle[j])
        {
            j++;
        }

        if (needle[j] == '\0')
            return i;
    }

    return -1;
}

int main()
{
    char haystack[100], needle[100];
    fgets(haystack, sizeof(haystack), stdin);
    fgets(needle, sizeof(needle), stdin);

    int i = 0;
    while (haystack[i] != '\0')
    {
        if (haystack[i] == '\n')
        {
            haystack[i] = '\0';
            break;
        }
        i++;
    }

    i = 0;
    while (needle[i] != '\0')
    {
        if (needle[i] == '\n')
        {
            needle[i] = '\0';
            break;
        }
        i++;
    }
    int index = find_substring(haystack, needle);

    printf("%d", index);
    return 0;
}