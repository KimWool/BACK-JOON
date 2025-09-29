#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(Node* root, int value) {
    if (value < root->value) {
        if (root->left == NULL) {
            root->left = createNode(value);
        } else {
            insert(root->left, value);
        }
    } else {
        if (root->right == NULL) {
            root->right = createNode(value);
        } else {
            insert(root->right, value);
        }
    }
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\n", root->value);
}

int main() {
    Node* root = NULL;
    int value;
    while (scanf("%d", &value) != EOF) {
        if (root == NULL) {
            root = createNode(value);
        } else {
            insert(root, value);
        }
    }
    postorder(root);
    return 0;
}