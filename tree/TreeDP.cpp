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

// Tree DP 예시 (서브트리 내 선택 최대값)
// 점화식: dp[u] = max(0, sum(dp[v] - cost)) + 자기값
// 시간복잡도: O(N)
const int MAXN = 100005;
vector<int> tree[MAXN];
int dp[MAXN], value[MAXN];

void tree_dp(int u, int p) {
    dp[u] = value[u];
    for (int v : tree[u]) {
        if (v == p) continue;
        tree_dp(v, u);
        dp[u] += max(0, dp[v]);
    }
}
