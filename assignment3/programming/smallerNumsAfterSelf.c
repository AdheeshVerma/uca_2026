#include <stdio.h>

typedef struct
{
    int value;
    int index;
} Pair;

void numAfterSelf(Pair arr[], int ans[], int low, int high);
void numMerger(Pair arr[], int ans[], int low, int mid, int high);

int main(void)
{
    int n;
    scanf("%d", &n);

    Pair arr[n];
    int ans[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].value);
        arr[i].index = i;
        ans[i] = 0;
    }

    numAfterSelf(arr, ans, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }

    printf("\n");

    return 0;
}

void numAfterSelf(Pair arr[], int ans[], int low, int high)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    numAfterSelf(arr, ans, low, mid);
    numAfterSelf(arr, ans, mid + 1, high);

    numMerger(arr, ans, low, mid, high);
}

void numMerger(Pair arr[], int ans[], int low, int mid, int high)
{
    int size = high - low + 1;
    Pair temp[size];

    int ptr1 = low;
    int ptr2 = mid + 1;
    int k = 0;
    int rightCount = 0;

    while (ptr1 <= mid && ptr2 <= high)
    {
        if (arr[ptr2].value < arr[ptr1].value)
        {
            temp[k++] = arr[ptr2++];
            rightCount++;
        }
        else
        {
            ans[arr[ptr1].index] += rightCount;
            temp[k++] = arr[ptr1++];
        }
    }

    while (ptr1 <= mid)
    {
        ans[arr[ptr1].index] += rightCount;
        temp[k++] = arr[ptr1++];
    }

    while (ptr2 <= high)
    {
        temp[k++] = arr[ptr2++];
    }

    for (int i = 0; i < size; i++)
    {
        arr[low + i] = temp[i];
    }
}