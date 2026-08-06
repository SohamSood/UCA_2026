#include <stdio.h>

int isPower2(int x) {
    return !!x & !(x >> 31) & !(x & (x + ~0));
}

int main() {
    int x = 8;

    int result = isPower2(x);

    return 0;
}