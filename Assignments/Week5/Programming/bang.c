#include <stdio.h>
int getByte(int a,int b) {
        return (a >> (b << 3)) & 0xFF;
}
int main() {
        int a = 6;
        int b = 2;
        printf("%d",getByte(a,b));
}