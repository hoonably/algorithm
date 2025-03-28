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

// Sliding Window (슬라이딩 윈도우)
// 고정 길이 또는 조건 만족하는 최소/최대 구간 문제
// 시간복잡도: O(N)

int min_len_subarray_sum_at_least_K(vector<int> &a, int K) {
    int n = a.size();
    int l = 0, sum = 0, ans = n + 1;

    for (int r = 0; r < n; ++r) {
        sum += a[r];
        while (sum >= K) {
            ans = min(ans, r - l + 1);
            sum -= a[l++];
        }
    }
    return ans == n + 1 ? -1 : ans;
}
