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

// Lowest Common Ancestor (LCA - Binary Lifting)
// logN 시간에 두 노드의 최소 공통 조상 구하기
// 시간복잡도: O(NlogN) 전처리, O(logN) 질의
struct LCA {
    int LOG;
    int N;
    vector<vector<int>> up;
    vector<int> depth;

    LCA(int n) : N(n) {
        LOG = 0;
        while ((1 << LOG) <= N) LOG++;
        up.assign(N, vector<int>(LOG));
        depth.assign(N, 0);
    }

    void dfs(int u, int p, vector<vector<int>> &tree) {
        up[u][0] = p;
        for (int i = 1; i < LOG; i++)
            up[u][i] = up[up[u][i-1]][i-1];

        for (int v : tree[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u, tree);
            }
        }
    }

    void build(int root, vector<vector<int>> &tree) {
        dfs(root, root, tree);
    }

    int get_lca(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);
        for (int i = LOG - 1; i >= 0; i--)
            if (depth[u] - (1 << i) >= depth[v])
                u = up[u][i];

        if (u == v) return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }
        return up[u][0];
    }
};
