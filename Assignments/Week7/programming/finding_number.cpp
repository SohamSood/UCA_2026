#include <iostream>
using namespace std;
#include <vector>
using namespace std;

int findno(vector<int>& arr) {
    vector<int> freq(32,0);
    for(int x:arr) {
        for(int i = 0;i<32;i++) {
            if((x & (1<<i)) != 0) {
                freq[i]++;
            }
        }
    } 
    int ans = 0;
    for(int i = 0;i<32;i++) {
        if(freq[i] % 3 != 0) {
            ans = ans | (1<<i);
        }
    }
    return ans;
}
int main() {
    vector<int> arr = {1,1,1,1,2,2,2};
    cout<<findno(arr);
}