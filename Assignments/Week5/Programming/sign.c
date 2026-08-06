#include <stdio.h>

int sign(int x) {
    return (x >> 31) | (!!x);
}

int main() {
    int x = -23;

    int result = sign(x);

    return 0;
}