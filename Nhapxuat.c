#include <stdio.h>
#include <stdlib.h>
typedef struct Node {  // 8bytes
    int data;
    struct Node *next;
} Node;

void print(Node *head) {
    Node *cur = head;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

int main() {
    Node *newnode, *head = NULL;
    int n;
    scanf("%d", &n);

    newnode = malloc(sizeof(Node));  // Cấp phát bộ nhớ cho node mới
    head = newnode;

    for (int i = 0; i < n; i++) {
        scanf("%d", &newnode->data);
        if (i < n - 1) {
            newnode->next = malloc(sizeof(Node));  // Cấp phát bộ nhớ cho node tiếp theo
            newnode = newnode->next;
        } else                     // Nếu là node cuối cùng thì gán next = NULL
            newnode->next = NULL;  // do đặt i=0 nên lấy max là n-1
    }
    print(head);
}