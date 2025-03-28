#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;
// --------------------------------------------------------------------

// Tree DFS / BFS
// 트리 탐색의 기본, 방문 여부 체크 필요 없음 (cycle X)
// 시간복잡도: O(N)

void dfs(int u, int parent, vector<vector<int>> &tree) {
    for (int v : tree[u]) {
        if (v == parent) continue;
        dfs(v, u, tree);
    }
}

void bfs(int root, vector<vector<int>> &tree) {
    queue<int> q;
    q.push(root);
    vector<bool> visited(tree.size(), false);
    visited[root] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : tree[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}
