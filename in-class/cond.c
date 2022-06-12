#include <stdio.h>

int main() {
    printf("Hello, world!\n");

#ifdef GERMAN
    printf("Gruess Gott, Welt!\n");
#endif

#ifdef LATIN
    printf("Vale!\n");
#endif

#ifdef GERMAN
    printf("Nein! Deutsch ist besser!\n");
#endif
}
