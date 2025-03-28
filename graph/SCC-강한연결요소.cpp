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

// SCC (Strongly Connected Components)
// 타잔 알고리즘 기반 템플릿 (코사라주보다 실전에서 더 자주 씀)
// 1-based 노드 사용
// scc.get_scc(N) 이후 SCCs에 각 그룹이 저장됨
const int MAXN = 101;
struct SCC {
    int id = 0;
    int d[MAXN];              // 각 노드의 dfs 번호
    bool finished[MAXN];      // SCC로 처리 완료 여부
    int SCCID[MAXN];          // 노드가 속한 SCC 번호
    vector<int> graph[MAXN];
    vector<vector<int>> SCCs;
    stack<int> stk;

    int dfs(int x) {
        d[x] = ++id;
        stk.push(x);

        int parent = d[x];
        for (int nxt : graph[x]) {
            if (d[nxt] == -1)
                parent = min(parent, dfs(nxt));
            else if (!finished[nxt])
                parent = min(parent, d[nxt]);
        }

        if (parent == d[x]) {  // 사이클 루트인 경우
            vector<int> scc;
            while (true) {
                int t = stk.top(); stk.pop();
                finished[t] = true;
                SCCID[t] = SCCs.size();
                scc.push_back(t);
                if (t == x) break;
            }
            SCCs.push_back(scc);
        }
        return parent;
    }

    void get_scc(int N) {
        memset(d, -1, sizeof(d));
        memset(finished, 0, sizeof(finished));
        for (int i = 1; i <= N; ++i)
            if (d[i] == -1)
                dfs(i);
    }

    void clear(int N) {
        id = 0;
        SCCs.clear();
        while (!stk.empty()) stk.pop();
        for (int i = 1; i <= N; ++i) graph[i].clear();
    }
}scc;
