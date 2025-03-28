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

// Bipartite Matching (DFS 기반)
// A 그룹 → B 그룹으로 매칭을 구성하는 기본 이분 매칭 알고리즘
// 각 A[i]에서 DFS로 매칭 가능한 B를 찾음 (O(NM))
// graph[u] = 연결된 B 노드 리스트 (0-based), match[v] = B의 매칭 상대 A
bool dfs(int u, vector<vector<int>> &graph, vector<int> &match, vector<bool> &visited) {
    for (int v : graph[u]) {
        if (visited[v]) continue;
        visited[v] = true;
        if (match[v] == -1 || dfs(match[v], graph, match, visited)) {
            match[v] = u;
            return true;
        }
    }
    return false;
}

int bipartite_matching(int N, int M, vector<vector<int>> &graph) {
    vector<int> match(M, -1);  // B 그룹의 매칭 상대
    int result = 0;
    for (int u = 0; u < N; ++u) {
        vector<bool> visited(M, false);
        if (dfs(u, graph, match, visited)) result++;
    }
    return result;
}


// Hungarian Algorithm (완전 이분 매칭, 최소 비용 매칭)
// cost[i][j]: i와 j를 매칭했을 때의 비용 → 최소 비용 매칭
// N개의 노드를 N개에 완전히 매칭 (N x N)
// 시간복잡도: O(N^3)
const int INF = 1e9;

int hungarian(int N, vector<vector<int>> &cost) {
    vector<int> u(N+1), v(N+1), p(N+1), way(N+1);
    for (int i = 1; i <= N; ++i) {
        p[0] = i;
        vector<int> minv(N+1, INF);
        vector<bool> used(N+1, false);
        int j0 = 0;
        do {
            used[j0] = true;
            int i0 = p[j0], delta = INF, j1;
            for (int j = 1; j <= N; ++j) {
                if (!used[j]) {
                    int cur = cost[i0-1][j-1] - u[i0] - v[j];
                    if (cur < minv[j]) {
                        minv[j] = cur;
                        way[j] = j0;
                    }
                    if (minv[j] < delta) {
                        delta = minv[j];
                        j1 = j;
                    }
                }
            }
            for (int j = 0; j <= N; ++j) {
                if (used[j]) {
                    u[p[j]] += delta;
                    v[j] -= delta;
                } else {
                    minv[j] -= delta;
                }
            }
            j0 = j1;
        } while (p[j0] != 0);

        do {
            int j1 = way[j0];
            p[j0] = p[j1];
            j0 = j1;
        } while (j0);
    }
    return -v[0];  // 최소 비용
}
