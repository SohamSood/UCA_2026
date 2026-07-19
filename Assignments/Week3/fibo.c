#include <stdio.h>

// Brute Force
int bruteForce(int n) {
    int a = 1, b = 1;
    int sum = 0;

    while (a <= n) {
        if (a % 2 == 0)
            sum += a;

        int c = a + b;
        a = b;
        b = c;
    }

    return sum;
}

// Optimized
int optimized(int n) {
    int first = 2;
    int second = 8;
    int sum = 0;

    while (first <= n) {
        sum += first;

        int next = 4 * second + first;
        first = second;
        second = next;
    }

    return sum;
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    printf("Brute Force: %d\n", bruteForce(n));
    printf("Optimized : %d\n", optimized(n));

    return 0;
}

