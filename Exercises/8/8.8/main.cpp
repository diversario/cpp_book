#include "stdlib.h"

long int prng(int max) {
    return ((1103515245*rand() + 12345) % 2147483648)%max;
}

int main() {
    int max = 50;

    int i=0;

    long int rand = prng(max);

    while (100>i++) {
        printf("%ld\n", rand);
        rand = prng(max);
    }

    return 0;
}
