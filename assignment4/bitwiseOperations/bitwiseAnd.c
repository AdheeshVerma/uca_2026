#include <stdio.h>
int bitAnd(int a, int b)
{
    return ~(~a | ~b);
}
int main()
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    printf("Bitwise and of %d and %d is: %d", num1, num2, bitAnd(num1, num2));
    return 0;
}