#include <stdio.h> 
int bitAnd(int a,int b) {
	return ~(~a | ~b);
}
int main() {
	int a = 6;
	int b = 5;
	printf("%d",bitAnd(a,b));
}
