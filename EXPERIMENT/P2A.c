#include <stdio.h>

int main() {
    int a[5], i;
    int *p = a;

    printf("Enter 5 elements: ");
    for (i = 0; i < 5; i++)
        scanf("%d", p + i);

    printf("Array in reverse order: ");
    for (i = 4; i >= 0; i--)
        printf("%d ", *(p + i));

    return 0;
}
