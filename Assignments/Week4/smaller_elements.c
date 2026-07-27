#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Pair;

void merge(Pair* nums, int left, int mid, int right, int* ans) {
    Pair* temp = (Pair*)malloc((right - left + 1) * sizeof(Pair));

    int i = left;
    int j = mid + 1;
    int k = 0;
    int rightCount = 0;

    while (i <= mid && j <= right) {
        if (nums[i].val <= nums[j].val) {
            ans[nums[i].idx] += rightCount;
            temp[k++] = nums[i++];
        } else {
            rightCount++;
            temp[k++] = nums[j++];
        }
    }

    while (i <= mid) {
        ans[nums[i].idx] += rightCount;
        temp[k++] = nums[i++];
    }

    while (j <= right) {
        temp[k++] = nums[j++];
    }

    for (i = left, k = 0; i <= right; i++, k++)
        nums[i] = temp[k];

    free(temp);
}

void mergeSort(Pair* nums, int left, int right, int* ans) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(nums, left, mid, ans);
    mergeSort(nums, mid + 1, right, ans);

    merge(nums, left, mid, right, ans);
}

int* countSmaller(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    int* ans = (int*)calloc(numsSize, sizeof(int));

    Pair* arr = (Pair*)malloc(numsSize * sizeof(Pair));

    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }

    mergeSort(arr, 0, numsSize - 1, ans);

    free(arr);

    return ans;
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    int returnSize;
    int* ans = countSmaller(nums, n, &returnSize);

    for (int i = 0; i < returnSize; i++)
        printf("%d ", ans[i]);

    free(ans);

    return 0;
}
