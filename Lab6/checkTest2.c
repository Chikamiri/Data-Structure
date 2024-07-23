#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data, score;
    char name[20], city[20];

    struct node* next;
} node;

int main() {
    FILE* input = fopen("bai5.inp", "r");
    FILE* output = fopen("bai5.out", "w");

    node *newnode, *head = NULL, *tail = NULL;
    int count = 0;
    int n, x;
    char temp[20];
    fscanf(input, "%d %d %s", &n, &x, temp);
    for (int i = 0; i < n; i++) {
        newnode = malloc(sizeof(node));
        fscanf(input, "%d %d %s %s", &newnode->data, &newnode->score, newnode->name, newnode->city);
        newnode->next = NULL;
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
        if (x <= newnode->score && strcmp(newnode->city, temp) == 0) {
            count++;
        }
    }
    fprintf(output, "Tinh: %s\n", temp);
    fprintf(output, "Tong so thi sinh trung tuyen: %d\n", count);

    node* cur = head;
    while (cur != NULL) {
        if (cur->score >= x && strcmp(cur->city, temp) == 0) {
            fprintf(output, "%d %d %s\n", cur->data, cur->score, cur->name);
        }
        cur = cur->next;
    }
    fclose(input);
    fclose(output);
}