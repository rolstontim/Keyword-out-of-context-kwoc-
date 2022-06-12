/* This little bit of code is meant to serve as a warning around
 * the sizeof() operator.  To avoid confusion, it should *only*
 * ever be used to determine the number of bytes required to
 * represent some data type. It should *not* be used to determine
 * the size of an array (even though this kind of usage is present
 * in the wild); using it for such a purpose can result in 
 * confusion.
 */

#include <stdlib.h>
#include <stdio.h>

#define ARRAY_SIZE 128

void init(int *histogram) {
    printf("Inside init(): %lu\n", sizeof(histogram));
    /* Why such small numbers in the output??! */
}


int main(int argc, char *argv[]) {
    int size;
    int data1[ARRAY_SIZE];
    
    if (argc > 1) {
        size = atoi(argv[1]);
    } else {
        size = ARRAY_SIZE;
    }

    int data2[size];  /* THIS IS NOT GOOD STYLE! */

    printf("Inside main() -- for data1: %lu\n", sizeof(data1));
    init(data1);

    printf("------------------------\n");

    printf("Inside main() -- for data2: %lu\n", sizeof(data2));
    init(data2);

    exit(0);
}
