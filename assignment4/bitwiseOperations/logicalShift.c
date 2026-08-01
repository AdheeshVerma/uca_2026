#include <stdio.h>

int logicalShift(int a, int n)
{
    int mask = ~(((1 << 31) >> n) << 1);
    return (a >> n) & mask;
}
int main(void)
{
    int num, places;
    scanf("%x %d", &num, &places);

    printf("%x", logicalShift(num, places));
    return 0;
}
