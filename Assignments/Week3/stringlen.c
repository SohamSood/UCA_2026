#include <stdio.h>
int main() {
	char str[100];
	scanf("%s",str);
	int len = 0;
	while(str[len] != '\0') {
		len++;
	}
	printf("length of string is %d",len);
	return 0;
}

