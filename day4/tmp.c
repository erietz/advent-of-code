#include <stdio.h>

int main() {
    int test;

    test = 0;
    printf("%i\n", test);

    test = 1;

    if (test == 1) {
        test = 234;
    }

    printf("%i\n", test);

    test = 0;
    printf("%i\n", test);

    return 0;
}
