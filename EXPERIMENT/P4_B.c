#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int main() {
    char exp[100];
    int st[100], top = -1, i, a, b;
    char c;

    printf("Enter postfix expression: ");
    scanf("%99s", exp);

    for (i = 0; exp[i] != '\0'; i++) {
        c = exp[i];

        if (isdigit((unsigned char)c)) {
            st[++top] = c - '0';
        } else if (c == '+' || c == '-' || c == '*' ||
                   c == '/' || c == '^') {
            if (top < 1) {
                printf("Invalid expression.\n");
                return 0;
            }

            b = st[top--];
            a = st[top--];

            switch (c) {
            case '+': st[++top] = a + b; break;
            case '-': st[++top] = a - b; break;
            case '*': st[++top] = a * b; break;
            case '/':
                if (b == 0) {
                    printf("Division by zero.\n");
                    return 0;
                }
                st[++top] = a / b;
                break;
            case '^': st[++top] = (int)pow(a, b); break;
            }
        } else {
            printf("Invalid character.\n");
            return 0;
        }
    }

    if (top != 0)
        printf("Invalid expression.\n");
    else
        printf("Result = %d\n", st[top]);

    return 0;
}
