#include <stdio.h>
#include <stdlib.h>
typedef struct Node {  // 8bytes
    int data;
    struct Node* next;
} Node;

Node* create(int x) {
    Node* newnode = malloc(sizeof(Node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
void print(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}
void insert(Node** head, int k, int x) {
    Node* newnode = create(x);

    // if k=1, insert at the beginning
    if (k == 1) {
        newnode->next = *head;
        *head = newnode;
        return;
    }

    // Find k-1-th node
    Node* cur = *head;
    for (int i = 1; i < k - 1 && cur != NULL; i++) {
        cur = cur->next;
    }
    if (cur != NULL) {  // insert
        newnode->next = cur->next;
        cur->next = newnode;
    }
}

int main() {
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);
    Node* head = NULL;
    Node* cur = NULL;
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);
        Node* newnode = create(tmp);
        if (head == NULL) {
            head = newnode;
            cur = newnode;
        } else {
            cur->next = newnode;
            cur = newnode;
        }
    }
    insert(&head, k, x);
    print(head);
}