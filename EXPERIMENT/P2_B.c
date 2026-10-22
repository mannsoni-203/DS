#include <stdio.h>

void callByValue(int x) {
    x = x + 10;
    printf("Inside call by value: %d\n", x);
}

void callByReference(int *x) {
    *x = *x + 10;
    printf("Inside call by reference: %d\n", *x);
}

int main() {
    int a = 10, b = 10;

    callByValue(a);
    printf("After call by value: %d\n", a);

    callByReference(&b);
    printf("After call by reference: %d\n", b);

    return 0;
}
