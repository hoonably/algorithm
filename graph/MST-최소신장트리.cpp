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

// Kruskal (크루스칼)
// edges는 {weight, u, v} 형태로 저장
// 정점은 1-based 또는 0-based 자유롭게 맞춰서 쓰면 됨
struct UnionFind {
    vector<int> parent;
    UnionFind(int n) : parent(n+1) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    bool merge(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        parent[b] = a;
        return true;
    }
};
int kruskal(int V, vector<tuple<int, int, int>> &edges) {
    UnionFind uf(V);
    sort(edges.begin(), edges.end());  // weight 기준 정렬

    int total_weight = 0;
    for (auto &[w, u, v] : edges) {
        if (uf.merge(u, v))
            total_weight += w;
    }
    return total_weight;
}


// Prim (프림)
// graph[u] = {v, weight} 형식의 인접 리스트
int prim(int V, vector<vector<pair<int, int>>> &graph) {
    vector<bool> visited(V+1, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, 1});  // {weight, node}

    int total_weight = 0;
    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        total_weight += w;

        for (auto &[v, cost] : graph[u]) {
            if (!visited[v]) pq.push({cost, v});
        }
    }
    return total_weight;
}
