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

// 2-SAT (Satisfiability 문제, SCC로 해결)
// add_clause(x, x_val, y, y_val)는 (x == x_val) or (y == y_val) 의미
// solve()가 true면 만족 가능하고, assignment[i]에 결과가 들어감

struct TwoSAT {
    int N;
    vector<vector<int>> graph, rev_graph;
    vector<int> order, comp;
    vector<bool> visited, assignment;

    TwoSAT(int n) : N(n) {
        graph.resize(2*N);
        rev_graph.resize(2*N);
        visited.resize(2*N);
        comp.resize(2*N);
        assignment.resize(N);
    }

    int NOT(int x) { return x ^ 1; } // true → false, false → true

    void add_clause(int x, bool x_true, int y, bool y_true) {
        // x_true == true → x가 참일 때
        x = 2*x + !x_true;
        y = 2*y + !y_true;
        graph[NOT(x)].push_back(y);
        graph[NOT(y)].push_back(x);
        rev_graph[y].push_back(NOT(x));
        rev_graph[x].push_back(NOT(y));
    }

    void dfs1(int u) {
        visited[u] = true;
        for (int v : graph[u])
            if (!visited[v]) dfs1(v);
        order.push_back(u);
    }

    void dfs2(int u, int label) {
        comp[u] = label;
        for (int v : rev_graph[u])
            if (comp[v] == -1) dfs2(v, label);
    }

    bool solve() {
        fill(visited.begin(), visited.end(), false);
        order.clear();

        for (int i = 0; i < 2*N; i++)
            if (!visited[i]) dfs1(i);

        fill(comp.begin(), comp.end(), -1);
        int label = 0;

        for (int i = 2*N - 1; i >= 0; i--) {
            int u = order[i];
            if (comp[u] == -1) dfs2(u, label++);
        }

        for (int i = 0; i < N; i++) {
            if (comp[2*i] == comp[2*i+1]) return false;  // 모순 발생
            assignment[i] = comp[2*i] < comp[2*i+1];     // 참이면 true
        }
        return true;
    }
};
