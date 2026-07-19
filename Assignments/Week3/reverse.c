#include <stdio.h>
	
void reverse_string(char* str,int len) {
    int i = 0;
    int j = len - 1;

    while (i < j) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }

}
int main() {
    char str[100];

    scanf("%s", str);

    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    reverse_string(str,len);
    printf("%s\n", str);
    return 0;
}  
