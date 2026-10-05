#include <stdio.h>

int main()
{
    int arr[100], n, i;
    int *ptr;

    printf("Enter number of elements: ");
    scanf("%d",&n);

    printf("Enter elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    ptr = &arr[n-1];

    printf("Array in Reverse Order:\n");

    for(i=0;i<n;i++)
    {
        printf("%d ", *ptr);
        ptr--;
    }

    return 0;
}
