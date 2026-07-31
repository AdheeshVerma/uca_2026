#include <stdio.h>
int bang(int num)
{
    return (0 & num) == num;
}
int main()
{
    int num;
    scanf("%d", &num);
    printf("Bang(!) of %d is %d", num, bang(num));
    return 0;
}