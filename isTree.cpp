#include <iostream>
using namespace std;

int N;
int x, y;
int father[1001];
int setSize[1001];

void init(int N) {
    for (int i = 0; i < N; i++) {
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
bool isSAmeSet(int x, int y) {
    return find(x) == find(y);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    int nodeCnt = 1;
    init(N);
    for (int i = 0; i < N - 1; i++) {
        cin >> x >> y;
        if (!isSAmeSet(x, y)) {
            unionTwoSet(x, y);
            nodeCnt++;
        }
    }
    cout << (nodeCnt == N ? "true" : "false") << "\n";
    return 0;
}