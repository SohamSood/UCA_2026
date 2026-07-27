#include <stdio.h>
#include <stdlib.h>

int merge(int* nums, int left, int mid, int right) {
    int count = 0;

    int* temp = (int*)malloc((right - left + 1) * sizeof(int));

    int i = left;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            count += (mid - i + 1);
            temp[k++] = nums[j++];
        }
    }

    while (i <= mid)
        temp[k++] = nums[i++];

    while (j <= right)
        temp[k++] = nums[j++];

    for (i = left, k = 0; i <= right; i++, k++)
        nums[i] = temp[k];

    free(temp);

    return count;
}

int mergeSort(int* nums, int left, int right) {
    if (left >= right)
        return 0;

    int mid = left + (right - left) / 2;

    int count = 0;

    count += mergeSort(nums, left, mid);
    count += mergeSort(nums, mid + 1, right);

    count += merge(nums, left, mid, right);

    return count;
}

int countInversions(int* nums, int numsSize) {
    if (numsSize <= 1)
        return 0;

    return mergeSort(nums, 0, numsSize - 1);
}

int main() {
    int nums[] = {2, 4, 1, 3, 5};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("%d\n", countInversions(nums, n));

    return 0;
}
