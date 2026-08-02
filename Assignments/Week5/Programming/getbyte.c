#include <stdio.h> 
int getByte(int a,int b) {
	return (1 & (a>>b));
}
int main() {
	int a = 6;
	int b = 2;
	printf("%d",getByte(a,b));
}
