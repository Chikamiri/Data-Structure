#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;
Node* create(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}
Node* insert(Node* node, int val) {
    if (node == NULL) return create(val);
    // val is less than node's value, to left
    // val is greater than node's value, to right
    if (val < node->val)
        node->left = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);
    return node;
}
Node* search(Node* node, int tmp) {
    // if node is NULL or node's value is equal to tmp, return node
    if (node == NULL || node->val == tmp) return node;
    // if node's value is greater than tmp, search in left subtree
    if (node->val < tmp) return search(node->right, tmp);
    return search(node->left, tmp);
}

void print(Node* node) {
    if (node == NULL) {
        printf("NULL");
        return;
    }
    if (node->left)
        printf("%d ", node->left->val);
    else
        printf("NULL ");
    if (node->right)
        printf("%d", node->right->val);
    else
        printf("NULL");
}
int main() {
    int n, x;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &x);

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        root = insert(root, a[i]);
    }
    Node* tmp = search(root, x);
    print(tmp);
}