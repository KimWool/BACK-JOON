#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHILD 100
#define MAX_STR 16

typedef struct Node {
    char str[MAX_STR];
    struct Node **children;
    int child_count;
} Node;

Node* createNode(const char* str) {
    Node* node = (Node*)malloc(sizeof(Node));
    strcpy(node->str, str);
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void insert(Node* root, char** path, int depth) {
    Node* current = root;
    for (int i = 0; i < depth; i++) {
        int found = 0;
        for (int j = 0; j < current->child_count; j++) {
            if (strcmp(current->children[j]->str, path[i]) == 0) {
                current = current->children[j];
                found = 1;
                break;
            }
        }
        if (!found) {
            Node* newNode = createNode(path[i]);
            current->children = realloc(current->children, sizeof(Node*) * (current->child_count + 1));
            current->children[current->child_count++] = newNode;

            // 정렬 (삽입 후 버블정렬)
            for (int j = current->child_count - 1; j > 0; j--) {
                if (strcmp(current->children[j - 1]->str, current->children[j]->str) > 0) {
                    Node* temp = current->children[j];
                    current->children[j] = current->children[j - 1];
                    current->children[j - 1] = temp;
                }
            }

            current = newNode;
        }
    }
}

void print(Node* node, int depth) {
    if (depth > 0) {
        for (int i = 0; i < depth - 1; i++) printf("--");
        printf("%s\n", node->str);
    }
    for (int i = 0; i < node->child_count; i++) {
        print(node->children[i], depth + 1);
    }
}

void freeTrie(Node* node) {
    for (int i = 0; i < node->child_count; i++) {
        freeTrie(node->children[i]);
    }
    free(node->children);
    free(node);
}

int main() {
    int N;
    scanf("%d", &N);

    Node* root = createNode("");

    for (int i = 0; i < N; i++) {
        int K;
        scanf("%d", &K);
        char** path = (char**)malloc(sizeof(char*) * K);
        for (int j = 0; j < K; j++) {
            path[j] = (char*)malloc(sizeof(char) * MAX_STR);
            scanf("%s", path[j]);
        }
        insert(root, path, K);
        for (int j = 0; j < K; j++) free(path[j]);
        free(path);
    }

    print(root, 0);
    freeTrie(root);

    return 0;
}