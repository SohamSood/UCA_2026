#include <stdio.h>

int find_substring(const char *haystack,const char *needle) {
    int i, j;

    for (i = 0; haystack[i] != '\0'; i++) {
        for (j = 0; needle[j] != '\0'; j++) {
            if (haystack[i + j] != needle[j])
                break;
        }

        if (needle[j] == '\0')
            return i;
    }

    return -1;
}

int main() {
    char haystack[] = "Embedded Systems";
    char needle[] = "bed";

    printf("%d", find_substring(haystack, needle));

    return 0;
}

