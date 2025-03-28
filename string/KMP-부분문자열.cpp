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

// KMP (부분 문자열 검색 알고리즘)
// 시간복잡도: O(N + M)

vector<int> get_pi(const string &pattern) {
    int m = pattern.size();
    vector<int> pi(m, 0);
    for (int i = 1, j = 0; i < m; ++i) {
        while (j > 0 && pattern[i] != pattern[j])
            j = pi[j - 1];
        if (pattern[i] == pattern[j]) pi[i] = ++j;
    }
    return pi;
}

vector<int> kmp_search(const string &text, const string &pattern) {
    vector<int> pi = get_pi(pattern);
    vector<int> res;
    int n = text.size(), m = pattern.size();
    for (int i = 0, j = 0; i < n; ++i) {
        while (j > 0 && text[i] != pattern[j])
            j = pi[j - 1];
        if (text[i] == pattern[j]) {
            if (j == m - 1) {
                res.push_back(i - m + 1);  // 매칭 시작 위치
                j = pi[j];
            } else j++;
        }
    }
    return res;
}
