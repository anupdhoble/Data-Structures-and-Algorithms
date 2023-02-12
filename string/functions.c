#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, world!";
    char substring[] = "world";

    char *result = strstr(str, substring);
    if (result) {
        printf("Substring found at index %ld\n", result );
    } else {
        printf("Substring not found\n");
    }

    return 0;
}
