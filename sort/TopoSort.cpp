#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int N, M;

vector<vector<int>> graph;
int indegree[200001];
int queue[200001];
int l, r;
void init() {
    graph = vector<vector<int>>(N + 1);
    // fill(indegree, indegree + N + 1, 0);
    memset(indegree, 0, (N + 1) * sizeof(int));
    l = r = 0;
}

int topoSort() {
    for (int i = 1; i <= N; i++) {
        if (indegree[i] == 0) {
            queue[r++] = i;
        }
    }
    if (r == 0) {
        return -1;
    }
    while (l < r) {
        int from = queue[l++];
        vector<int> next = graph[from];
        for (int to : next) {
            indegree[to]--;
            if (indegree[to] == 0) {
                queue[r++] = to;
            }
        }
    }
    return r == N ? 0 : -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;

    init();
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;

        graph[from].push_back(to);
        indegree[to]++;
    }

    if (topoSort() == -1) {
        cout << -1 << "\n";
    } else {
        for (int i = 0; i < N - 1; i++) {
            cout << queue[i] << " ";
        }
        cout << queue[N - 1] << "\n";
    }

    return 0;
}