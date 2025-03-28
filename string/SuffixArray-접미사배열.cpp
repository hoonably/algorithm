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

// Suffix Array (접미사 배열) + LCP (최장 공통 접두사)
// 시간복잡도: O(N logN)

vector<int> get_suffix_array(const string &s) {
    int n = s.size(), gap;
    vector<int> sa(n), pos(n), tmp(n);

    iota(sa.begin(), sa.end(), 0);
    copy(s.begin(), s.end(), pos.begin());

    for (gap = 1;; gap <<= 1) {
        auto cmp = [&](int a, int b) {
            if (pos[a] != pos[b]) return pos[a] < pos[b];
            int ra = a + gap < n ? pos[a + gap] : -1;
            int rb = b + gap < n ? pos[b + gap] : -1;
            return ra < rb;
        };
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for (int i = 1; i < n; ++i)
            tmp[sa[i]] = tmp[sa[i - 1]] + cmp(sa[i - 1], sa[i]);
        pos = tmp;
        if (pos[sa[n - 1]] == n - 1) break;
    }
    return sa;
}

vector<int> get_lcp(const string &s, const vector<int> &sa) {
    int n = s.size(), k = 0;
    vector<int> rank(n), lcp(n);
    for (int i = 0; i < n; ++i) rank[sa[i]] = i;
    for (int i = 0; i < n; ++i) {
        if (rank[i]) {
            int j = sa[rank[i] - 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k]) ++k;
            lcp[rank[i]] = k;
            if (k) --k;
        }
    }
    return lcp;
}
