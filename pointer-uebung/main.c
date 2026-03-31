#include <stdlib.h>
#include <stdio.h>

int main() {
    int *x = malloc(sizeof(int));
    *x = 5;
    printf("%i\n", *x);
    int *y = malloc(sizeof(int));
    *y = 3;
    printf("%i\n", *y);
    return EXIT_SUCCESS;
}