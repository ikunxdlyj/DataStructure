#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int prim(vector<vector<pair<int, int>>> &graph, int V, int E) {
    bool visited[V + 1] = {};
    auto cmp = [](pair<int, int> p1, pair<int, int> p2) -> bool {
        return p1.second > p2.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> heap(cmp);

    int nodeCnt = 1;
    visited[1] = true;
    int ans = 0;
    for (const pair<int, int> &p : graph[1]) {
        heap.push(p);
    }
    while (!heap.empty()) {
        pair<int, int> p = heap.top();
        heap.pop();
        int to = p.first;
        int val = p.second;
        if (!visited[to]) {
            visited[to] = true;
            nodeCnt++;
            ans += val;
            if (nodeCnt == V) {
                return ans;
            }
            for (const pair<int, int> &p : graph[to]) {
                heap.push(p);
            }
        }
    }
    return nodeCnt == V ? ans : -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int V, E;
    int from, to, val;
    cin >> V >> E;
    vector<vector<pair<int, int>>> graph(V + 1);
    for (int i = 0; i < E; i++) {
        cin >> from >> to >> val;
        graph[from].push_back({to, val});
        graph[to].push_back({from, val});
    }
    cout << prim(graph, V, E) << "\n";
    return 0;
}