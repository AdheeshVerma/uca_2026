#include <stdio.h>
int isPower2(int num)
{
    if (num == 0)
        return 0;
    if ((num & (num - 1)) == 0)
        return 1;
    return 0;
}
int main()
{
    int num;
    scanf("%d", &num);
    if (isPower2(num) == 1)
        printf("%d is a power of 2", num);
    else
        printf("%d is not a power of 2", num);
    return 0;
}