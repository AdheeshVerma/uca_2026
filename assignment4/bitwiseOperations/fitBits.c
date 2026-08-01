#include <stdio.h>

int fitBits(int x, int n)
{
    int shift = 32 + (~n + 1);
    return !(((x << shift) >> shift) ^ x);
}
int main(void)
{
    int x, n;
    scanf("%d %d", &x, &n);

    int ans = fitBits(x, n);
    printf("%d", ans);
    return 0;
}
