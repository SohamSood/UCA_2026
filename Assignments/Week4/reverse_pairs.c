#include <stdio.h>
#include <stdlib.h>

int merge(int* nums, int left, int mid, int right) {
    int count = 0;

    int j = mid + 1;
    for (int i = left; i <= mid; i++) {
        while (j <= right && (long long)nums[i] > 2LL * nums[j]) {
            j++;
        }
        count += j - (mid + 1);
    }

    int* temp = (int*)malloc((right - left + 1) * sizeof(int));

    int i = left;
    j = mid + 1;
    int k = 0;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
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

int reversePairs(int* nums, int numsSize) {
    if (numsSize <= 1)
        return 0;

    return mergeSort(nums, 0, numsSize - 1);
}

int main() {
    int nums[] = {1, 3, 2, 3, 1};
    int n = sizeof(nums) / sizeof(nums[0]);

    printf("%d\n", reversePairs(nums, n));

    return 0;
}


// class Solution {
// public:
//     int ans = 0;
//     void merge(vector<int>& nums,int left,int mid,int right) {

//         int l = mid-left+1;
//         int r = right - mid;
//         int k = right-left;
//         vector<int> lefty;
//         vector<int> righty;

//         for(int i = left;i<=mid;i++) {
//             lefty.push_back(nums[i]);
//         }

//         for(int i = mid+1;i<=right;i++) {
//             righty.push_back(nums[i]);
//         }

//         int leftindex = 0;
//         for(int i = 0;i<righty.size();i++) {
//             while(leftindex < lefty.size() && lefty[leftindex] <= 2LL * righty[i]) {
//                 leftindex++;
//             }
//             ans+=lefty.size()-leftindex;
//             // cout<<"left part -> ";
//             // for(int x:lefty) cout<<x<<" ";
//             // cout<<endl<<"right part -> ";
//             // for(int x:righty) cout<<x<<" ";
//             // cout<<endl<<"this value "<<(lefty.size()-leftindex) << " , ans -> " <<ans<<endl<<endl;
//         }

//         int i = 0;
//         int j = 0;
//         int index = left;
//         while(i < l && j < r) {
//             if(lefty[i] <= righty[j]) {
//                 nums[index++] = lefty[i++];
//             } else {
//                 nums[index++] = righty[j++];
//             }
//         }
//         while(i<l) {
//             nums[index++] = lefty[i++];
//         }
//         while(j<r) {
//             nums[index++] = righty[j++];
//         }
//     } 
//     void mergesort(vector<int>& nums,int left,int right) {
//         if(left < right) {
//             int mid = left+(right-left)/2;
//             mergesort(nums,left,mid);
//             mergesort(nums,mid+1,right);
//             merge(nums,left,mid,right);
//         }
//     }
//     int reversePairs(vector<int>& nums) {
//         mergesort(nums,0,nums.size()-1);
//         return ans;
//     }
// };