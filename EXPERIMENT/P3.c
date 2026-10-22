#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push() {
    int x;
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d", &x);
    stack[++top] = x;
    printf("Element pushed.\n");
}

void pop() {
    if (top == -1)
        printf("Stack Underflow\n");
    else
        printf("Popped element: %d\n", stack[top--]);
}

void peek() {
    if (top == -1)
        printf("Stack is empty.\n");
    else
        printf("Top element: %d\n", stack[top]);
}

void display() {
    int i;
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    int ch;
    do {
        printf("\n1.Push 2.Pop 3.Peek 4.Display 5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1: push(); break;
        case 2: pop(); break;
        case 3: peek(); break;
        case 4: display(); break;
        case 5: break;
        default: printf("Invalid choice.\n");
        }
    } while (ch != 5);

    return 0;
}
