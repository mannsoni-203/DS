#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeg(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    if (!n) { printf("Memory error.\n"); return; }
    n->data = x;
    n->next = head;
    head = n;
}

void insertEnd(int x) {
    struct Node *n = malloc(sizeof(struct Node));
    struct Node *t = head;

    if (!n) { printf("Memory error.\n"); return; }
    n->data = x;
    n->next = NULL;

    if (!head) {
        head = n;
        return;
    }

    while (t->next) t = t->next;
    t->next = n;
}

void insertAfter(int key, int x) {
    struct Node *t = head, *n;

    while (t && t->data != key) t = t->next;
    if (!t) { printf("Node not found.\n"); return; }

    n = malloc(sizeof(struct Node));
    if (!n) { printf("Memory error.\n"); return; }
    n->data = x;
    n->next = t->next;
    t->next = n;
}

void deleteFirst() {
    struct Node *t;
    if (!head) { printf("List is empty.\n"); return; }
    t = head;
    head = head->next;
    free(t);
}

void deleteLast() {
    struct Node *t = head;

    if (!head) { printf("List is empty.\n"); return; }
    if (!head->next) {
        free(head);
        head = NULL;
        return;
    }

    while (t->next->next) t = t->next;
    free(t->next);
    t->next = NULL;
}

void deleteAfter(int key) {
    struct Node *t = head, *d;

    while (t && t->data != key) t = t->next;
    if (!t || !t->next) {
        printf("Node or next node not found.\n");
        return;
    }

    d = t->next;
    t->next = d->next;
    free(d);
}

void display() {
    struct Node *t = head;

    if (!t) { printf("List is empty.\n"); return; }
    printf("List: ");
    while (t) {
        printf("%d -> ", t->data);
        t = t->next;
    }
    printf("NULL\n");
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
