#include <algorithm>
#include <array>
#include <iostream>
using namespace std;
int N, M;
// int arr[200002][3];
array<array<int, 3>, 200002> arr;

int fathers[200002];
int setSize[200002];
void init(int N) {
    for (int i = 1; i <= N; i++) {
        fathers[i] = i;
        setSize[i] = 1;
    }
}
int find(int x) {
    if (fathers[x] != x) {
        fathers[x] = find(fathers[x]);
    }
    return fathers[x];
}
void unionTwoSets(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) {
        return;
    }
    if (setSize[fx] > setSize[fy]) {
        fathers[fy] = fx;
        setSize[fx] += setSize[fy];
    } else {
        fathers[fx] = fy;
        setSize[fy] += setSize[fx];
    }
}
bool isSameSet(int x, int y) {
    return find(x) == find(y);
}

int kruskal() {
    init(N);
    auto cmp = [](const array<int, 3> &a, const array<int, 3> &b) {
        return a[2] < b[2];
    };
    sort(arr.begin(), arr.begin() + M, cmp);
    int ans = 0;
    int nodeCnt = 1;
    for (int i = 0; i < M; i++) {
        int from = arr[i][0], to = arr[i][1], weight = arr[i][2];
        if (!isSameSet(from, to)) {
            unionTwoSets(from, to);
            ans += weight;
            nodeCnt++;
        }
    }
    return nodeCnt == N ? ans : -1;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    int ans = kruskal();
    if (ans == -1) {
        cout << "orz" << "\n";
    } else {
        cout << ans << "\n";
    }
    return 0;
}