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

// Edmonds-Karp Algorithm (최대 유량 - BFS 기반 Ford-Fulkerson)
// 시간복잡도: O(VE^2)
// cap[u][v]: u→v 용량, flow[u][v]: 현재 유량
// adj[u]: 연결된 노드 리스트
int edmonds_karp(int N, int source, int sink, vector<vector<int>> &cap, vector<vector<int>> &adj) {
    vector<vector<int>> flow(N, vector<int>(N, 0));
    int max_flow = 0;

    while (true) {
        vector<int> parent(N, -1);
        queue<int> q;
        q.push(source);
        parent[source] = source;

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            for (int nxt : adj[cur]) {
                if (parent[nxt] == -1 && cap[cur][nxt] - flow[cur][nxt] > 0) {
                    parent[nxt] = cur;
                    q.push(nxt);
                    if (nxt == sink) break;
                }
            }
        }

        if (parent[sink] == -1) break;  // 더 이상 증가 경로 없음

        int aug = 1e9;
        for (int i = sink; i != source; i = parent[i])
            aug = min(aug, cap[parent[i]][i] - flow[parent[i]][i]);
        for (int i = sink; i != source; i = parent[i]) {
            flow[parent[i]][i] += aug;
            flow[i][parent[i]] -= aug;
        }
        max_flow += aug;
    }
    return max_flow;
}


// Dinic's Algorithm (최대 유량)
// 레벨 그래프 + 블로킹 플로우 방식 → O(V^2E), 일반적으로 빠름
struct Edge {
    int to, rev, cap;
};
struct Dinic {
    int N;
    vector<vector<Edge>> G;
    vector<int> level, ptr;

    Dinic(int n) : N(n) {
        G.resize(N);
        level.resize(N);
        ptr.resize(N);
    }

    void add_edge(int u, int v, int cap) {
        G[u].push_back({v, (int)G[v].size(), cap});
        G[v].push_back({u, (int)G[u].size() - 1, 0});  // 역방향
    }

    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &e : G[u]) {
                if (e.cap && level[e.to] == -1) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }

    int dfs(int u, int t, int flow) {
        if (u == t) return flow;
        for (int &i = ptr[u]; i < G[u].size(); ++i) {
            Edge &e = G[u][i];
            if (e.cap && level[e.to] == level[u] + 1) {
                int pushed = dfs(e.to, t, min(flow, e.cap));
                if (pushed) {
                    e.cap -= pushed;
                    G[e.to][e.rev].cap += pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t) {
        int total = 0;
        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (int pushed = dfs(s, t, 1e9))
                total += pushed;
        }
        return total;
    }
};


// Minimum Cut (최소 컷)
// 최대 유량 계산 후, source에서 도달 가능한 정점 vs 불가능한 정점으로 나눠 분할
// Dinic 또는 Edmonds-Karp 수행 후 사용 가능
// 시간복잡도: O(V+E)
vector<int> min_cut(int N, int s, vector<vector<int>> &cap, vector<vector<int>> &flow, vector<vector<int>> &adj) {
    vector<bool> visited(N, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!visited[v] && cap[u][v] - flow[u][v] > 0) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    vector<int> cut;
    for (int u = 0; u < N; ++u) {
        if (visited[u]) {
            for (int v : adj[u]) {
                if (!visited[v] && cap[u][v] > 0) {
                    cut.push_back(u);  // 컷에 포함되는 u (또는 (u,v)로 저장 가능)
                }
            }
        }
    }
    return cut;  // 최소 컷을 이루는 edge의 from-node 리스트 반환
}
