#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *next;
    struct Node *prev;
} Node;
int main() {
    int n;
    scanf("%d", &n);

    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->val = x;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    Node *cur = head;
    while (cur != NULL) {
        printf("%d ", cur->val);
        cur = cur->next;
    }
    printf("\n");

    cur = tail;
    while (cur != NULL) {
        printf("%d ", cur->val);
        cur = cur->prev;
    }
}