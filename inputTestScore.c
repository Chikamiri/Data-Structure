#include <stdio.h>
#include <stdlib.h>
typedef struct Node {  // 12bytes
    int id;
    int data;
    struct Node* next;
} Node;

Node* create(int id, int data) {
    Node* newnode = malloc(sizeof(Node));
    newnode->id = id;
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
void print(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        printf("%d %d\n", cur->id, cur->data);
        cur = cur->next;
    }
}
void insert(Node** head, int id, int data) {
    Node* newnode = create(id, data);

    if (*head == NULL || (*head)->id > id) {
        newnode->next = *head;
        *head = newnode;
        return;
    }

    Node* cur = *head;
    while (cur->next != NULL && cur->next->id < id) {
        cur = cur->next;
    }
    newnode->next = cur->next;
    cur->next = newnode;
}

int main() {
    int n;
    scanf("%d", &n);

    Node* head = NULL;
    for (int i = 0; i <= n; i++) {
        int tmp, val;
        scanf("%d %d", &tmp, &val);
        insert(&head, tmp, val);
    }
    print(head);
}