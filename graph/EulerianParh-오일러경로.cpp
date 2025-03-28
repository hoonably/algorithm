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

// Eulerian Path / Circuit (오일러 경로/회로)
// 무방향 그래프 기준 (유향도 유사하게 구현 가능)
// 조건: 모든 정점 차수 짝수 → 회로, 두 개만 홀수 → 경로
// 시간복잡도: O(E)
vector<int> eulerian_path(int V, vector<vector<int>> &graph) {
    vector<vector<int>> g = graph;  // 원본 유지
    vector<int> path;
    stack<int> stk;
    stk.push(0);  // 시작점 설정

    while (!stk.empty()) {
        int u = stk.top();
        if (!g[u].empty()) {
            int v = g[u].back(); g[u].pop_back();
            auto &w = g[v];
            w.erase(find(w.begin(), w.end(), u));  // 양방향 간선 제거
            stk.push(v);
        } else {
            path.push_back(u);
            stk.pop();
        }
    }
    reverse(path.begin(), path.end());
    return path;  // 오일러 경로 or 회로
}
