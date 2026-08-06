#include <stdio.h>

int minimizedMaximum(int populations[], int n, int k) {
    int low = 1, high = 0;
    for (int i = 0; i < n; i++) {
        if (populations[i] > high)
            high = populations[i];
    }
    while (low < high) {
        int mid = low + (high - low) / 2;
        int requiredClinics = 0;
        for (int i = 0; i < n; i++) {
            requiredClinics += (populations[i] + mid - 1) / mid; 
        }
        if (requiredClinics <= k) high = mid;      
        else low = mid + 1;   
    }
    return low;
}

int main() {
    int n, k;

    printf("Enter number of villages: ");
    scanf("%d", &n);
    int populations[n];
    printf("Enter populations of villages:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &populations[i]);
    }
    printf("Enter total number of clinics: ");
    scanf("%d", &k);
    printf("Minimum possible maximum load on any clinic = %d\n",minimizedMaximum(populations, n, k));
    return 0;
}