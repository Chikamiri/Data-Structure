#include <stdio.h>
#include <stdlib.h>
typedef struct Node {  // 8bytes
    int id;
    int data;
    struct Node* next;
} Node;

Node* create(int x, int d) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->id = x;
    newnode->data = d;
    newnode->next = NULL;
    return newnode;
}

void check(Node* head, int n) {
    Node* cur = head;
    while (cur != NULL) {
        if (cur->id == n) {
            printf("%d", cur->data);
            return;
        }
        cur = cur->next;
    }
    printf("No data");
}
int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    Node* head = NULL;
    Node* cur = NULL;

    for (int i = 0; i < n; i++) {
        int tmp, d;
        scanf("%d %d", &tmp, &d);
        Node* newnode = create(tmp, d);
        if (head == NULL) {
            head = newnode;
            cur = newnode;
        } else {
            cur->next = newnode;
            cur = newnode;
        }
    }

    check(head, x);
}