#include <stdio.h>
#include <stdlib.h>
typedef struct Node {  // 12bytes
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

int Count(Node* head, int n) {
    int count = 0;
    Node* cur = head;
    while (cur != NULL) {
        if (cur->data >= n) {
            count++;
        }
        cur = cur->next;
    }
    return count;
}
void print(Node* head, int n) {
    Node* cur = head;
    printf("Tong so sinh vien tham du ky thi cuoi ky: %d\n", Count(head, n));
    while (cur != NULL) {
        if (cur->data >= n) {
            printf("%d %d\n", cur->id, cur->data);
        }
        cur = cur->next;
    }
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

    print(head, x);
}