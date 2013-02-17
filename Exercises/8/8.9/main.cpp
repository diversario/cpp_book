#include "stdlib.h"

long int prng(long int max) {
    return (((long int)1103515245*rand() + 12345) % 2147483648)%max;
}

int main() {
    int max = 55;
    int min = 50;

    int i=0;

    while (100>i++) {
        printf("%d\n", prng(max - min)+min);
    }



    return 0;
}
