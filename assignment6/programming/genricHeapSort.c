#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*cmp)(void *, void *);

void swap(void *left, void *right, int size)
{
    void *buffer = malloc(size);
    memcpy(buffer, left, size);
    memcpy(left, right, size);
    memcpy(right, buffer, size);
    free(buffer);
}

int cmpInt(void *left, void *right)
{
    if (*(int *)left == *(int *)right)
        return 0;
    return *(int *)left > *(int *)right ? 1 : -1;
}

int cmpFloat(void *left, void *right)
{
    if (*(float *)left == *(float *)right)
        return 0;
    return *(float *)left > *(float *)right ? 1 : -1;
}

int cmpChar(void *left, void *right)
{
    if (*(char *)left == *(char *)right)
        return 0;
    return *(char *)left > *(char *)right ? 1 : -1;
}

int cmpString(void *left, void *right)
{
    return strcmp(*(char **)left, *(char **)right);
}

void heapify(void *arr, int size, int index, int elem_size, cmp cmp)
{
    int largest = index;
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    if (left < size && (cmp((char *)arr + largest * elem_size,
                            (char *)arr + left * elem_size) < 0))
    {
        largest = left;
    }
    if (right < size && (cmp((char *)arr + largest * elem_size,
                             (char *)arr + right * elem_size) < 0))
    {
        largest = right;
    }

    if (largest != index)
    {
        swap((char *)arr + largest * elem_size, (char *)arr + index * elem_size,
             elem_size);
        heapify(arr, size, largest, elem_size, cmp);
    }
}

void heapSort(void *arr, int size, int elem_size, cmp cmp)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(arr, size, i, elem_size, cmp);
    }

    for (int i = size - 1; i >= 0; i--)
    {
        swap(arr, (char *)arr + i * elem_size, elem_size);
        heapify(arr, i, 0, elem_size, cmp);
    }
}

void printIntArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void printFloatArray(float *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
}

void printCharArray(char *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("'%c' ", arr[i]);
    printf("\n");
}

void printStringArray(char **arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("'%s' ", arr[i]);
    printf("\n");
}

int main(void)
{
    int arr_int[] = {7, 9, 8, 6, 2, 1, 0, 4, 8, 6};
    printf("int array before: ");
    printIntArray(arr_int, sizeof(arr_int) / sizeof(arr_int[0]));
    heapSort(arr_int, sizeof(arr_int) / sizeof(arr_int[0]), sizeof(int),
             cmpInt);
    printf("int array after: ");
    printIntArray(arr_int, sizeof(arr_int) / sizeof(arr_int[0]));
    printf("\n");

    float arr_float[] = {5.98, 4.25, 6.21, 0.54, 8.212, 0.48, 9.20};
    printf("float array before: ");
    printFloatArray(arr_float, sizeof(arr_float) / sizeof(arr_float[0]));
    heapSort(arr_float, sizeof(arr_float) / sizeof(arr_float[0]),
             sizeof(float), cmpFloat);
    printf("float array after: ");
    printFloatArray(arr_float, sizeof(arr_float) / sizeof(arr_float[0]));
    printf("\n");

    char arr_char[] = {'a', 'd', 'h', 'e', 'e', 's', 'h'};
    printf("char array before: ");
    printCharArray(arr_char, sizeof(arr_char) / sizeof(arr_char[0]));
    heapSort(arr_char, sizeof(arr_char) / sizeof(arr_char[0]), sizeof(char),
             cmpChar);
    printf("char array after: ");
    printCharArray(arr_char, sizeof(arr_char) / sizeof(arr_char[0]));
    printf("\n");

    char *arr_str[] = {"Adheesh Here", "testing HeapSort", "heorsdk", "1234-9876"};
    printf("string array before: ");
    printStringArray(arr_str, sizeof(arr_str) / sizeof(arr_str[0]));
    heapSort(arr_str, sizeof(arr_str) / sizeof(arr_str[0]), sizeof(char *),
             cmpString);
    printf("string array after: ");
    printStringArray(arr_str, sizeof(arr_str) / sizeof(arr_str[0]));

    return 0;
}