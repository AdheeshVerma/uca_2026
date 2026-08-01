#include <stdio.h>

int getByte(int a, int n)
{
    return (a >> (n << 3)) & 0xFF;
}
int main(void)
{
    int num, nBit;
    scanf("%x %d", &num, &nBit);

    printf("%x", getByte(num, nBit));
    return 0;
}
