#include <stdio.h>

int conditional(int x, int y, int z) {
    int mask = ~!!x + 1;
    return (mask & y) | (~mask & z);
}

int main() {
    int x = 2;
    int y = 4;
    int z = 5;

    int result = conditional(x, y, z);

    return 0;
}