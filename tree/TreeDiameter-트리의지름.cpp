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

// Tree Diameter (트리의 지름)
// 임의의 노드에서 가장 먼 노드를 찾고, 그 노드에서 다시 가장 먼 노드까지 거리 측정
// 시간복잡도: O(N)

pair<int, int> farthest_node(int start, vector<vector<pair<int,int>>> &tree) {
    vector<int> dist(tree.size(), -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    int max_dist = 0, far_node = start;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto &[v, w] : tree[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + w;
                q.push(v);
                if (dist[v] > max_dist) {
                    max_dist = dist[v];
                    far_node = v;
                }
            }
        }
    }
    return {far_node, max_dist};
}

int tree_diameter(vector<vector<pair<int,int>>> &tree) {
    auto [u, _] = farthest_node(0, tree);
    auto [v, diameter] = farthest_node(u, tree);
    return diameter;
}
