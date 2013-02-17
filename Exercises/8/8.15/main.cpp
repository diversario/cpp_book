#include "../std_lib_facilities.h"

void f(const int i) {
    printf("Const int: %d\n", i);
}

int main() {
    f(4);
    return 0;
}
