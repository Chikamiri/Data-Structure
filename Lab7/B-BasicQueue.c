#include <stdio.h>
#include <stdlib.h>
struct Node {
    int val;
    struct Node* next;
};
struct Queue {
    struct Node* head;
    struct Node* tail;
};
struct Queue* create() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->head = q->tail = NULL;
    return q;
}
void enqueue(struct Queue* q, int val) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->val = val;
    newnode->next = NULL;

    // Queue is empty-->head=tail=newnode
    if (q->tail == NULL) {
        q->head = q->tail = newnode;
        return;
    }
    q->tail->next = newnode;
    q->tail = newnode;
}
void dequeue(struct Queue* q) {
    if (q->head == NULL) {
        return;
    }

    struct Node* tmp = q->head;
    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }
    free(tmp);
}
int isEmpty(struct Queue* q) {
    return q->head == NULL;
}
int peek(struct Queue* q) {
    if (q->head == NULL) {
        return -1;
    }
    return q->head->val;
}
int main() {
    struct Queue* q = create();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(q, x);
    }
    while (!isEmpty(q)) {
        printf("%d ", peek(q));
        dequeue(q);
    }
}