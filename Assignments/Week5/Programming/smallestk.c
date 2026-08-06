// chart link -> {https://docs.google.com/spreadsheets/d/1r_RspQeVddOb2Ou_4ggnCmrjGMqGoNYRy-zDoiSE9EQ/edit?usp=sharing}
#include <stdio.h>
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int left, int right) {
  int pivot = arr[left];
  int start = left;
  int end = right;
  while (start < end) {
    while (start <= right && arr[start] <= pivot) start++;
    while (arr[end] > pivot) end--;
    if (start < end) swap(&arr[start], &arr[end]);
  }
  swap(&arr[left], &arr[end]);
  return end;
}

void quickSelect(int arr[], int left, int right, int k) {
  if (left >= right) return;
  int loc = partition(arr, left, right);
  if (loc == k - 1)
    return;
  else if (loc > k - 1)
    quickSelect(arr, left, loc - 1, k);
  else
    quickSelect(arr, loc + 1, right, k);
}

int main() {
  int n, k;
  printf("Enter number of elements: ");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the elements:\n");
  for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
  printf("Enter K: ");
  scanf("%d", &k);
  if (k <= 0 || k > n) {
    printf("Invalid value of K\n");
    return 0;
  }
  quickSelect(arr, 0, n - 1, k);
  printf("First %d smallest elements (any order):\n", k);
  for (int i = 0; i < k; i++) printf("%d ", arr[i]);
  return 0;
}