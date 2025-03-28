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

// BFS (너비 우선 탐색)
// dist는 초기값 -1로 설정하면 방문 여부 겸 거리 저장 가능
void bfs(int start, vector<vector<int>> &graph, vector<int> &dist) {
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int nxt : graph[cur]) {
            if (dist[nxt] == -1) {  // 방문 체크
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
}

// Dijkstra (다익스트라 - 양의 가중치 그래프 최단 경로)
// graph[u] = {v, weight}인 인접 리스트 형태
void dijkstra(int start, vector<vector<pair<int, int>>> &graph, vector<int> &dist) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});  // {거리, 노드}

    while (!pq.empty()) {
        auto [cost, cur] = pq.top(); pq.pop();
        if (dist[cur] < cost) continue;

        for (auto &[nxt, w] : graph[cur]) {
            if (dist[nxt] > cost + w) {
                dist[nxt] = cost + w;
                pq.push({dist[nxt], nxt});
            }
        }
    }
}

// Bellman-Ford (음수 간선 허용, 음수 사이클 탐지 가능)
// edges는 {from, to, weight} 저장한 배열
bool bellman_ford(int start, int V, vector<tuple<int,int,int>> &edges, vector<int> &dist) {
    dist[start] = 0;
    for (int i = 1; i < V; i++) {
        for (auto &[u, v, w] : edges) {
            if (dist[u] == INF) continue;
            if (dist[v] > dist[u] + w)
                dist[v] = dist[u] + w;
        }
    }

    // 음수 사이클 존재 여부 확인
    for (auto &[u, v, w] : edges) {
        if (dist[u] == INF) continue;
        if (dist[v] > dist[u] + w) return true;  // 음수 사이클 있음
    }
    return false;
}

// Floyd-Warshall (모든 쌍 최단 경로, 음수 간선 가능 / 사이클 검출도 가능)
// 초기 dist[i][j] = INF, dist[i][i] = 0
// 음수 사이클은 dist[i][i] < 0 여부로 판단 가능
void floyd_warshall(int V, vector<vector<int>> &dist) {
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (dist[i][k] == INF || dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
