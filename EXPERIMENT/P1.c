#include <stdio.h>
#define MAX 100

int main() {
    int a[MAX], n, i, pos, value, key, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements: ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    do {
        printf("\n1.Insert  2.Delete  3.Traverse  4.Search  5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (n == MAX) {
                printf("Array is full.\n");
                break;
            }
            printf("Enter position and value: ");
            scanf("%d%d", &pos, &value);

            if (pos < 1 || pos > n + 1) {
                printf("Invalid position.\n");
                break;
            }

            for (i = n; i >= pos; i--)
                a[i] = a[i - 1];

            a[pos - 1] = value;
            n++;
            printf("Element inserted.\n");
            break;

        case 2:
            printf("Enter position to delete: ");
            scanf("%d", &pos);

            if (pos < 1 || pos > n) {
                printf("Invalid position.\n");
                break;
            }

            for (i = pos - 1; i < n - 1; i++)
                a[i] = a[i + 1];

            n--;
            printf("Element deleted.\n");
            break;

        case 3:
            printf("Array: ");
            for (i = 0; i < n; i++)
                printf("%d ", a[i]);
            printf("\n");
            break;

        case 4:
            printf("Enter element to search: ");
            scanf("%d", &key);

            for (i = 0; i < n && a[i] != key; i++);

            if (i < n)
                printf("Element found at position %d\n", i + 1);
            else
                printf("Element not found.\n");
            break;

        case 5:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}
