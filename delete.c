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
void removeNode(Node** head, int k) {
    if (k == 1) {
        Node* tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return;
    }

    Node* cur = *head;
    for (int i = 1; i < k - 1 && cur != NULL; i++) {
        cur = cur->next;
    }
    if (cur != NULL && cur->next != NULL) {
        Node* tmp = cur->next;
        cur->next = cur->next->next;
        free(tmp);
    }
}
void print(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
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
    removeNode(&head, k);
    print(head);
}