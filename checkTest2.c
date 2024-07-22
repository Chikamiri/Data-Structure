#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    int id;
    int data;
    char name[100];
    char city[100];
    struct Node* next;
} Node;

Node* create(int x, int d, char name[], char city[]) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->id = x;
    newnode->data = d;
    strcpy(newnode->name, name);
    strcpy(newnode->city, city);
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
    int n, x;  // x điểm chuẩn
    scanf("%d %d", &n, &x);

    Node* head = NULL;
    Node* cur = NULL;
    for (int i = 0; i < n; i++) {
        int tmp, d;
        char name[100], city[100];
        scanf("%d %d %c %c", &tmp, &d, &name, &city);
        Node* newnode = create(tmp, d, name, city);
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