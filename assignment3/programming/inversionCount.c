#include <stdio.h>
#include <stdlib.h>

int inversion(int arr[], int low, int high);
int mergeInversion(int arr[], int low, int mid, int high);

int main(void)
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int inversionCnt = inversion(arr, 0, n - 1);
    printf("%d\n", inversionCnt);
    return 0;
}

int inversion(int arr[], int low, int high)
{
    if (low >= high)
        return 0;

    int mid = low + (high - low) / 2;
    int count = 0;

    count += inversion(arr, low, mid);
    count += inversion(arr, mid + 1, high);
    count += mergeInversion(arr, low, mid, high);

    return count;
}

int mergeInversion(int arr[], int low, int mid, int high)
{
    int temp[high - low + 1];
    int k = 0;
    int ptr1 = low;
    int ptr2 = mid + 1;
    int count = 0;
    while (ptr1 <= mid && ptr2 <= high)
    {
        if (arr[ptr1] <= arr[ptr2])
        {
            temp[k++] = arr[ptr1++];
        }
        else
        {
            temp[k++] = arr[ptr2++];
            count += mid - ptr1 + 1;
        }
    }

    while (ptr1 <= mid)
    {
        temp[k++] = arr[ptr1++];
    }

    while (ptr2 <= high)
    {
        temp[k++] = arr[ptr2++];
    }
    k = 0;
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[k++];
    }
    return count;
}
