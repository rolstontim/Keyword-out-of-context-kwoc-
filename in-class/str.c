#include <string.h>
#include <stdio.h>

void function_a(char *s) {
    printf("function_a: %d %d\n", sizeof(s), strlen(s));
}


void main() {
    char buffer[100];

    strncpy(buffer, "The quick brownfox", 100);

    printf("main: %d %d\n", sizeof(buffer), strlen(buffer));

    function_a(buffer);
}
