#include <stdio.h>

int conditional(int x, int y, int z)
{
    int bitMask = ~(!x) + 1;
    return (~bitMask & y) | (bitMask & z);
}
int main(void)
{
    int num1, num2, num3;
    scanf("%d %d %d", &num1, &num2, &num3);

    printf("%d", conditional(num1, num2, num3));
    return 0;
}