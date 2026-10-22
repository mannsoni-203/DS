#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeg(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    struct Node *t;

    if (!n) { printf("Memory error.\n"); return; }
    n->data = x;

    if (!head) {
        head = n;
        n->next = head;
        return;
    }

    t = head;
    while (t->next != head) t = t->next;

    n->next = head;
    t->next = n;
    head = n;
}

void insertEnd(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    struct Node *t;

    if (!n) { printf("Memory error.\n"); return; }
    n->data = x;

    if (!head) {
        head = n;
        n->next = head;
        return;
    }

    t = head;
    while (t->next != head) t = t->next;

    t->next = n;
    n->next = head;
}

void insertAfter(int key, int x) {
    struct Node *t = head, *n;

    if (!head) { printf("List is empty.\n"); return; }

    do {
        if (t->data == key) {
            n = malloc(sizeof(struct Node));
            if (!n) { printf("Memory error.\n"); return; }

            n->data = x;
            n->next = t->next;
            t->next = n;
            return;
        }
        t = t->next;
    } while (t != head);

    printf("Node not found.\n");
}

void deleteFirst() {
    struct Node *t, *d;

    if (!head) { printf("List is empty.\n"); return; }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    t = head;
    while (t->next != head) t = t->next;

    d = head;
    head = head->next;
    t->next = head;
    free(d);
}

void deleteLast() {
    struct Node *t, *d;

    if (!head) { printf("List is empty.\n"); return; }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    t = head;
    while (t->next->next != head) t = t->next;

    d = t->next;
    t->next = head;
    free(d);
}

void deleteAfter(int key) {
    struct Node *t = head, *d;

    if (!head) { printf("List is empty.\n"); return; }

    do {
        if (t->data == key) {
            if (t->next == t) {
                printf("No node exists after this node.\n");
                return;
            }

            d = t->next;
            t->next = d->next;

            if (d == head) head = d->next;
            free(d);
            return;
        }
        t = t->next;
    } while (t != head);

    printf("Node not found.\n");
}

void display() {
    struct Node *t = head;

    if (!head) { printf("List is empty.\n"); return; }

    printf("Circular List: ");
    do {
        printf("%d -> ", t->data);
        t = t->next;
    } while (t != head);

    printf("(back to head)\n");
}

int main() {
    int ch, x, key;

    do {
        printf("\n1.Insert Beginning 2.Insert End 3.Insert After\n");
        printf("4.Delete First 5.Delete Last 6.Delete After\n");
        printf("7.Display 8.Exit\nChoice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            printf("Value: "); scanf("%d", &x);
            insertBeg(x); break;
        case 2:
            printf("Value: "); scanf("%d", &x);
            insertEnd(x); break;
        case 3:
            printf("After which value, and new value: ");
            scanf("%d%d", &key, &x);
            insertAfter(key, x); break;
        case 4: deleteFirst(); break;
        case 5: deleteLast(); break;
        case 6:
            printf("Delete node after value: ");
            scanf("%d", &key);
            deleteAfter(key); break;
        case 7: display(); break;
        case 8: break;
        default: printf("Invalid choice.\n");
        }
    } while (ch != 8);

    return 0;
}
