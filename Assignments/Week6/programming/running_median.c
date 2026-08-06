#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct {
    int maxHeap[MAX];
    int minHeap[MAX];
    int maxSize;
    int minSize;
} MedianFinder;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void maxHeapPush(MedianFinder *obj, int val) {
    int i = obj->maxSize++;
    obj->maxHeap[i] = val;

    while (i > 0) {
        int p = (i - 1) / 2;
        if (obj->maxHeap[p] >= obj->maxHeap[i])
            break;
        swap(&obj->maxHeap[p], &obj->maxHeap[i]);
        i = p;
    }
}

void minHeapPush(MedianFinder *obj, int val) {
    int i = obj->minSize++;
    obj->minHeap[i] = val;

    while (i > 0) {
        int p = (i - 1) / 2;
        if (obj->minHeap[p] <= obj->minHeap[i])
            break;
        swap(&obj->minHeap[p], &obj->minHeap[i]);
        i = p;
    }
}

int maxHeapTop(MedianFinder *obj) {
    return obj->maxHeap[0];
}

int minHeapTop(MedianFinder *obj) {
    return obj->minHeap[0];
}

void maxHeapPop(MedianFinder *obj) {
    obj->maxHeap[0] = obj->maxHeap[--obj->maxSize];

    int i = 0;
    while (1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int largest = i;

        if (l < obj->maxSize && obj->maxHeap[l] > obj->maxHeap[largest])
            largest = l;

        if (r < obj->maxSize && obj->maxHeap[r] > obj->maxHeap[largest])
            largest = r;

        if (largest == i)
            break;

        swap(&obj->maxHeap[i], &obj->maxHeap[largest]);
        i = largest;
    }
}

void minHeapPop(MedianFinder *obj) {
    obj->minHeap[0] = obj->minHeap[--obj->minSize];

    int i = 0;
    while (1) {
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        int smallest = i;

        if (l < obj->minSize && obj->minHeap[l] < obj->minHeap[smallest])
            smallest = l;

        if (r < obj->minSize && obj->minHeap[r] < obj->minHeap[smallest])
            smallest = r;

        if (smallest == i)
            break;

        swap(&obj->minHeap[i], &obj->minHeap[smallest]);
        i = smallest;
    }
}

MedianFinder* medianFinderCreate() {
    MedianFinder *obj = (MedianFinder *)malloc(sizeof(MedianFinder));
    obj->maxSize = 0;
    obj->minSize = 0;
    return obj;
}

void addNum(MedianFinder *obj, int num) {
    if (obj->minSize == 0) {
        minHeapPush(obj, num);
        return;
    }

    if (num >= minHeapTop(obj)) {
        if (obj->minSize == obj->maxSize) {
            minHeapPush(obj, num);
        } else {
            minHeapPush(obj, num);
            maxHeapPush(obj, minHeapTop(obj));
            minHeapPop(obj);
        }
    } else {
        if (obj->minSize == obj->maxSize) {
            maxHeapPush(obj, num);
            minHeapPush(obj, maxHeapTop(obj));
            maxHeapPop(obj);
        } else {
            maxHeapPush(obj, num);
        }
    }
}

double findMedian(MedianFinder *obj) {
    if (obj->maxSize == 0)
        return (double)minHeapTop(obj);

    if (obj->maxSize == obj->minSize)
        return ((double)maxHeapTop(obj) + (double)minHeapTop(obj)) / 2.0;

    return (double)minHeapTop(obj);
}

void medianFinderFree(MedianFinder *obj) {
    free(obj);
}

int main() {
    MedianFinder *obj = medianFinderCreate();

    addNum(obj, 1);
    printf("%.1f\n", findMedian(obj));

    addNum(obj, 2);
    printf("%.1f\n", findMedian(obj));

    addNum(obj, 3);
    printf("%.1f\n", findMedian(obj));

    addNum(obj, 4);
    printf("%.1f\n", findMedian(obj));

    addNum(obj, 5);
    printf("%.1f\n", findMedian(obj));

    addNum(obj, 6);
    printf("%.1f\n", findMedian(obj));

    medianFinderFree(obj);

    return 0;
}

//easy cpp leetcode solution
// class MedianFinder {
// public:
//     priority_queue<int> maxheap;
//     priority_queue<int,vector<int>,greater<int>> minheap;
//     MedianFinder() {
        
//     }
    
//     void addNum(int num) {
//         if(minheap.size() == 0) {
//             minheap.push(num);
//             return;
//         }
//         if(minheap.top() <= num) {
//             if(minheap.size() == maxheap.size()) {
//                 minheap.push(num);
//             } else {
//                 minheap.push(num);
//                 maxheap.push(minheap.top());
//                 minheap.pop();
//             }
//         } else {
//             if(minheap.size() == maxheap.size()) {
//                 maxheap.push(num);
//                 minheap.push(maxheap.top());
//                 maxheap.pop();
//             } else {
//                 maxheap.push(num);
//             }
//         }
//     }
    
//     double findMedian() {
//         if(maxheap.size() == 0) return minheap.top();
//         if(minheap.size() == maxheap.size()) return (double)(minheap.top() + maxheap.top()) / 2;
//         return minheap.top();
//     }
// };

// /**
//  * Your MedianFinder object will be instantiated and called as such:
//  * MedianFinder* obj = new MedianFinder();
//  * obj->addNum(num);
//  * double param_2 = obj->findMedian();
//  */