#include <stdio.h>

static void swap(int arr[], int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

static void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr, i, largest);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (i = n - 1; i > 0; i--)
    {
        swap(arr, 0, i);
        heapify(arr, i, 0);
    }
}

int main(void)
{
    int a[] = {1, 4, 85, 4, 36, 9, 7, 10, 52, 34, 7};
    int n = (int)(sizeof(a) / sizeof(a[0]));
    int i;

    heapSort(a, n);

    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}