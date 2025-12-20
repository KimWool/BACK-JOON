#include <stdio.h>

#define MAX 1000001
typedef long long ll;

ll arr[MAX];
ll tree[MAX * 4];
int N;

ll init(int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update(int node, int start, int end, int index, ll diff) {
    if (index < start || index > end) return;
    tree[node] += diff;
    if (start != end) {
        int mid = (start + end) / 2;
        update(node * 2, start, mid, index, diff);
        update(node * 2 + 1, mid + 1, end, index, diff);
    }
}

ll sum(int node, int start, int end, int left, int right) {
    if (right < start || end < left) return 0;
    if (left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    int M, K;
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%lld", &arr[i]);
    }

    init(1, 1, N);

    for (int i = 0; i < M + K; i++) {
        int a, b;
        ll c;
        scanf("%d %d %lld", &a, &b, &c);
        if (a == 1) {
            ll diff = c - arr[b];
            arr[b] = c;
            update(1, 1, N, b, diff);
        } else if (a == 2) {
            printf("%lld\n", sum(1, 1, N, b, (int)c));
        }
    }

    return 0;
}