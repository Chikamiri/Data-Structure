#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};
void push(struct Stack* s, int val) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->val = val;
    newnode->next = s->top;
    s->top = newnode;
}
void pop(struct Stack* s) {
    if (s->top == NULL) {
        return;
    }
    struct Node* tmp = s->top;
    s->top = s->top->next;
    free(tmp);
}
int top(struct Stack* s) {
    if (s->top == NULL) {
        return -1;
    }
    return s->top->val;
}
int isEmpty(struct Stack* s) {
    return s->top == NULL;
}
void init(struct Stack* s) {
    s->top = NULL;
}
int main() {
    int n, m;
    struct Stack st, tmp;
    init(&st);
    init(&tmp);
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        int s;
        scanf("%d", &s);
        push(&st, s);
    }
    for (int i = 0; i < m; i++) {
        pop(&st);
    }
    while (!isEmpty(&st)) {
        push(&tmp, top(&st));
        pop(&st);
    }
    while (!isEmpty(&tmp)) {
        printf("%d ", top(&tmp));
        pop(&tmp);
    }
}
