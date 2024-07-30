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
    if (val < node->val)
        node->left = insert(node->left, val);
    else if (val > node->val)
        node->right = insert(node->right, val);
    return node;
}
void preO(Node* node) {
    if (node == NULL) return;
    printf("%d ", node->val);
    // Traverse left subtree then right subtree
    preO(node->left);
    preO(node->right);
}
int main() {
    int n;
    scanf("%d", &n);

    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        root = insert(root, x);
    }
    preO(root);
}