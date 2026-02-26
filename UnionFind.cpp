#include <iostream>
using namespace std;

int N, M;
int father[1000002];
int setSize[1000002];
void init() {
    for (int i = 1; i <= N; i++) {
        father[i] = i;
        setSize[i] = 1;
    }
}
int find(int x) {
    if (x != father[x]) {
        father[x] = find(father[x]);
    }
    return father[x];
}
void unionTwoSet(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx == fy) {
        return;
    }
    if (setSize[fx] < setSize[fy]) {
        father[fx] = fy;
        setSize[fy] += setSize[fx];
    } else {
        father[fy] = fx;
        setSize[fx] += setSize[fy];
    }
}
bool isSameSet(int x, int y) {
    return find(x) == find(y);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M;
    init();
    for (int i = 0; i < M; i++) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            cout << (isSameSet(x, y) ? "Yes" : "No") << "\n";
        } else {
            unionTwoSet(x, y);
        }
    }
    return 0;
}