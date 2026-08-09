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

// class Tree {
// public:
//     int val = 0;
//     int indexleft;
//     int indexright;
//     Tree* left = NULL;
//     Tree* right = NULL;
//     Tree() {
    
//     }
//     Tree(int lefty,int righty) {
//         indexleft = lefty;
//         indexright = righty;
//     }
// };
// class Solution {
// public:
//     Tree* root = new Tree();
//     Tree* buildTree(int left,int right){
//         if(left>right) return NULL;
//         int mid = left+(right-left)/2;
//         Tree* newnode = new Tree(left,right);
//         if(left == right) return newnode;
//         newnode->left = buildTree(left,mid);
//         newnode->right = buildTree(mid+1,right);
//         return newnode;
//     }
//     void add(int index,Tree* root) {
//         if(root == NULL) return;
//         root->val++;
//         if(root->indexleft == root->indexright) return;
//         int mid = root->indexleft + (root->indexright - root->indexleft)/2;
//         if(index<=mid) {
//             add(index,root->left);
//         }else {
//             add(index,root->right);
//         }
//     }
//     int search(int left,int right,Tree* root) {
//         if(root == NULL) return 0;
//         if(root->val == 0) return root->val;
//         if(root->indexleft >= left && root->indexright <= right) return root->val;
//         if(root->indexleft > right || root->indexright < left) return 0;
//         return search(left,right,root->left) + search(left,right,root->right);
//     }
//     vector<int> countSmaller(vector<int>& nums) {
//         int maxelement = INT_MIN;
//         int minelement = INT_MAX;
//         for(int x:nums) maxelement = max(maxelement,x),minelement = min(minelement,x);
//         root = buildTree(minelement,maxelement);
//         // vector<int> ans(nums.size(),0);
//         for(int i = nums.size()-1;i>=0;i--) {
//             add(nums[i],root);
//             ans[i] = search(minelement,nums[i]-1,root);
//         }
//         return ans;
//     }
// };