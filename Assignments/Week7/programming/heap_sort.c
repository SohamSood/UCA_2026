#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (*Compare)(const void *, const void *);

void swap(void *a, void *b, size_t size) {
    void *temp = malloc(size);

    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);

    free(temp);
}

void heapify(void *arr, size_t n, size_t i, size_t size, Compare cmp) {
    size_t largest = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    char *base = (char *)arr;

    if (left < n && cmp(base + left * size, base + largest * size) > 0)
        largest = left;

    if (right < n && cmp(base + right * size, base + largest * size) > 0)
        largest = right;

    if (largest != i) {
        swap(base + i * size, base + largest * size, size);
        heapify(arr, n, largest, size, cmp);
    }
}

void heapSort(void *arr, size_t n, size_t size, Compare cmp) {
    for (int i = (int)n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, size, cmp);

    for (size_t i = n; i > 1; i--) {
        swap(arr, (char *)arr + (i - 1) * size, size);
        heapify(arr, i - 1, 0, size, cmp);
    }
}

int compareInt(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int arr[] = {5, 2, 8, 1, 9, 3};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n, sizeof(int), compareInt);

    for (size_t i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}