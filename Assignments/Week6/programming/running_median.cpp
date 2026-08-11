#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    MedianFinder() {
    }

    void addNum(int num) {
        if (minheap.size() == 0) {
            minheap.push(num);
            return;
        }

        if (minheap.top() <= num) {
            if (minheap.size() == maxheap.size()) {
                minheap.push(num);
            } else {
                minheap.push(num);
                maxheap.push(minheap.top());
                minheap.pop();
            }
        } else {
            if (minheap.size() == maxheap.size()) {
                maxheap.push(num);
                minheap.push(maxheap.top());
                maxheap.pop();
            } else {
                maxheap.push(num);
            }
        }
    }

    double findMedian() {
        if (maxheap.size() == 0)
            return minheap.top();

        if (minheap.size() == maxheap.size())
            return (double)(minheap.top() + maxheap.top()) / 2;

        return minheap.top();
    }
};

int main() {
    MedianFinder obj;

    obj.addNum(1);
    cout << obj.findMedian() << endl;

    obj.addNum(2);
    cout << obj.findMedian() << endl;

    obj.addNum(3);
    cout << obj.findMedian() << endl;

    obj.addNum(4);
    cout << obj.findMedian() << endl;

    obj.addNum(5);
    cout << obj.findMedian() << endl;

    return 0;
}