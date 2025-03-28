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

// Bitmask DP (부분집합 상태 저장)
// 예: 모든 노드를 방문하는 최소 비용 TSP
// 시간복잡도: O(N^2 * 2^N)

const int INF = 1e9;
int tsp(int n, vector<vector<int>> &cost) {
    vector<vector<int>> dp(1<<n, vector<int>(n, INF));
    dp[1][0] = 0;

    for (int mask = 1; mask < (1<<n); ++mask) {
        for (int u = 0; u < n; ++u) {
            if (!(mask & (1<<u))) continue;
            for (int v = 0; v < n; ++v) {
                if (mask & (1<<v)) continue;
                dp[mask | (1<<v)][v] = min(dp[mask | (1<<v)][v], dp[mask][u] + cost[u][v]);
            }
        }
    }

    return *min_element(dp[(1<<n)-1].begin(), dp[(1<<n)-1].end());
}
