#include <stdio.h>
int bitXor(int num1, int num2)
{
    return ~(~num1 & ~num2) & ~(num1 & num2);
}
int main()
{
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    printf("The bitwise XOR of %d and %d is %d", num1, num2, bitXor(num1, num2));
    return 0;
}