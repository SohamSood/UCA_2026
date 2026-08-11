#include <iostream>
#include <vector>
using namespace std;

bool possible(vector<int>& populations, int n, int k, int maxLoad) {
    int clinics = 0;

    for (int i = 0; i < n; i++) {
        clinics += (populations[i] + maxLoad - 1) / maxLoad;
    }

    return clinics <= k;
}

int main() {
    int n, k;

    cout << "Enter number of villages: ";
    cin >> n;

    vector<int> populations(n);

    cout << "Enter populations of villages:\n";
    for (int i = 0; i < n; i++) {
        cin >> populations[i];
    }

    cout << "Enter total number of clinics: ";
    cin >> k;

    int low = 1;
    int high = 0;

    for (int x : populations) {
        high = max(high, x);
    }

    while (low < high) {
        int mid = low + (high - low) / 2;

        if (possible(populations, n, k, mid))
            high = mid;
        else
            low = mid + 1;
    }

    cout << "Minimum possible maximum load = " << low << endl;

    return 0;
}