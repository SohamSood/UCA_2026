#include <stdio.h>
int logicalshift(int a,int b) {
        return (a>>b);
}
int main() {
        int a = 6;
        int b = 2;
        printf("%d",logicalshift(a,b));
}
~              
