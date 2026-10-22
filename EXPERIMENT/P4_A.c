#include <stdio.h>
#include <ctype.h>
#include <string.h>

char st[100];
int top = -1;

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int main() {
    char infix[100], postfix[100];
    int i, j = 0;
    char c;

    printf("Enter infix expression: ");
    scanf("%99s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        if (isalnum((unsigned char)c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            st[++top] = c;
        } else if (c == ')') {
            while (top != -1 && st[top] != '(')
                postfix[j++] = st[top--];

            if (top == -1) {
                printf("Invalid expression.\n");
                return 0;
            }
            top--;
        } else if (c == '+' || c == '-' || c == '*' ||
                   c == '/' || c == '^') {
            while (top != -1 && st[top] != '(' &&
                   (precedence(st[top]) > precedence(c) ||
                   (precedence(st[top]) == precedence(c) &&
                    c != '^'))) {
                postfix[j++] = st[top--];
            }
            st[++top] = c;
        } else {
            printf("Invalid character.\n");
            return 0;
        }
    }

    while (top != -1) {
        if (st[top] == '(') {
            printf("Invalid expression.\n");
            return 0;
        }
        postfix[j++] = st[top--];
    }

    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
