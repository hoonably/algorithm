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

// Heavy-Light Decomposition (HLD)
// 트리 경로 질의를 세그먼트 트리 등으로 처리 가능하게 분해
// 시간복잡도: O(log^2 N) ~ O(log N) per query
struct HLD {
    int n, cur_pos;
    vector<vector<int>> tree;
    vector<int> sz, in, out, top, par, depth;

    HLD(int N) : n(N), tree(N), sz(N), in(N), out(N),
                 top(N), par(N), depth(N), cur_pos(0) {}

    void add_edge(int u, int v) {
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int dfs(int u, int p) {
        sz[u] = 1;
        for (int &v : tree[u]) {
            if (v == p) continue;
            par[v] = u;
            depth[v] = depth[u] + 1;
            sz[u] += dfs(v, u);
            if (sz[v] > sz[tree[u][0]] || tree[u][0] == p)
                swap(v, tree[u][0]);
        }
        return sz[u];
    }

    void decompose(int u, int p, int tp) {
        in[u] = cur_pos++;
        top[u] = tp;
        for (int v : tree[u]) {
            if (v == p) continue;
            decompose(v, u, (v == tree[u][0] ? tp : v));
        }
        out[u] = cur_pos;
    }

    void build(int root = 0) {
        par[root] = -1;
        dfs(root, -1);
        decompose(root, -1, root);
    }

    // u~v 경로 쿼리 구간 반환 (seg tree 등에 사용 가능)
    void query_path(int u, int v, function<void(int,int)> f) {
        while (top[u] != top[v]) {
            if (depth[top[u]] < depth[top[v]]) swap(u, v);
            f(in[top[u]], in[u] + 1);
            u = par[top[u]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        f(in[u] + 1, in[v] + 1);  // 간선 쿼리 (노드 쿼리는 f(in[u], in[v]+1))
    }
};
