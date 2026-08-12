#include <stdio.h>
int findNum(int arr[], int n)
{
    int res = 0;
    for (int i = 0; i < 32; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if ((1 << i) & (arr[j]))
                count++;
        }
        if (count % 3 == 1)
        {
            res = (res << 1) | 1;
        }
    }
    return res;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 1, 2, 4, 1, 2, 1, 4, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d", findNum(arr, n));
    return 0;
}