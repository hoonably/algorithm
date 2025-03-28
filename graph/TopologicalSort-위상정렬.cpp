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

// Topological Sort (위상 정렬)
// DAG의 선후관계 정렬 (사이클이 없을 때만 유효)
// 시간복잡도: O(V+E)
vector<int> topological_sort(int V, vector<vector<int>> &graph) {
    vector<int> indegree(V, 0);
    for (int u = 0; u < V; ++u)
        for (int v : graph[u])
            indegree[v]++;

    queue<int> q;
    for (int i = 0; i < V; ++i)
        if (indegree[i] == 0) q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : graph[u]) {
            if (--indegree[v] == 0)
                q.push(v);
        }
    }

    // 사이클이 있는 경우: order.size() < V
    return order;
}
