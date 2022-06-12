#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

double function_one(double);
double function_two(double);


double function_one( double r ) {
    if (r < 10.0) {
        return r * 12.0;
    } else {
        return function_two( r/2 );
    }
}

double function_two( double s ) {
    if (s < 20.0) {
        return s - 2.0;
    } else {
        return function_one( s/1.3 );
    }
}



int main(int argc, char *argv[]) {
    double x;
    double y;

    assert (argc >= 2);
    x = atoi(argv[1]); 
    y = function_one(x);

    printf("%f\n", y);

    exit(0);
}
