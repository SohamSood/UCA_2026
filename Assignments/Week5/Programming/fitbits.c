#include <stdio.h>

int fitsBits(int x, int n) {
    int shift = 32 + (~n + 1);
    return !((((x << shift) >> shift) ^ x));
}

int main() {
    int x = 5;
    int n = 3;

    int result = fitsBits(x, n);

    return 0;
}