#include <stdio.h>
int bitXor(int a,int b) {
	return ~(~(a&~b) & ~(b&~a));
}
int main() {
	int a = 4,b = 5;
	printf("%d",bitXor(a,b));
	return 0;
}
