#include <stdio.h>
#include <stdlib.h>

int inorder[100001], postorder[100001], idxMap[100001];

void buildPreorder(int inStart, int inEnd, int postStart, int postEnd) {
    if (inStart > inEnd || postStart > postEnd) return;

    int root = postorder[postEnd];
    printf("%d ", root);

    int rootIndex = idxMap[root];
    int leftSize = rootIndex - inStart;

    buildPreorder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
    buildPreorder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
        idxMap[inorder[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    buildPreorder(0, n - 1, 0, n - 1);
    return 0;
}