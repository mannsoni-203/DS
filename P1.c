#include <stdio.h>

int main()
{
    int arr[100], n, i, choice, pos, value, key, found;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    do
    {
        printf("\n--- ARRAY MENU ---");
        printf("\n1. Insertion");
        printf("\n2. Deletion");
        printf("\n3. Traversal");
        printf("\n4. Search");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter position: ");
                scanf("%d", &pos);
                printf("Enter value: ");
                scanf("%d", &value);

                for(i = n; i >= pos; i--)
                    arr[i] = arr[i-1];

                arr[pos-1] = value;
                n++;
                break;

            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &pos);

                for(i = pos-1; i < n-1; i++)
                    arr[i] = arr[i+1];

                n--;
                break;

            case 3:
                printf("Array Elements: ");
                for(i = 0; i < n; i++)
                    printf("%d ", arr[i]);
                break;

            case 4:
                printf("Enter element to search: ");
                scanf("%d", &key);

                found = 0;
                for(i = 0; i < n; i++)
                {
                    if(arr[i] == key)
                    {
                        printf("Found at position %d", i+1);
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                    printf("Element not found");
                break;
        }

    } while(choice != 5);

    return 0;
}
