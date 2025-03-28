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

// 단절점 / 단절선
// Articulation Point / Bridge / Biconnected Components
// DFS Tree에서 발견 시간(dfn)과 저점(low) 사용
// 단절점: 제거 시 컴포넌트 수 증가, 단절선: 제거 시 연결 끊김
// 시간복잡도: O(V+E)
struct AP_Bridge {
    int V, id;
    vector<vector<int>> graph;
    vector<int> dfn, low;
    vector<bool> visited, is_cut;
    vector<pair<int, int>> bridges;

    AP_Bridge(int n) : V(n), id(0) {
        graph.resize(V);
        dfn.assign(V, -1);
        low.assign(V, 0);
        visited.assign(V, false);
        is_cut.assign(V, false);
    }

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);  // 무방향 그래프
    }

    void dfs(int u, int parent) {
        dfn[u] = low[u] = id++;
        int children = 0;

        for (int v : graph[u]) {
            if (v == parent) continue;
            if (dfn[v] == -1) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > dfn[u]) bridges.push_back({u, v});
                if (parent != -1 && low[v] >= dfn[u]) is_cut[u] = true;
                children++;
            } else {
                low[u] = min(low[u], dfn[v]);
            }
        }

        if (parent == -1 && children >= 2)
            is_cut[u] = true;
    }

    void find_ap_and_bridges() {
        for (int i = 0; i < V; ++i)
            if (dfn[i] == -1)
                dfs(i, -1);
    }
};
