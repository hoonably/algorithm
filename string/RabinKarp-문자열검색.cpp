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

// Rabin-Karp (Rolling Hash 문자열 검색)
// 시간복잡도: O(N + M), 단 해시 충돌 가능

const int MOD = 1e9 + 7, BASE = 256;

long long poly_hash(const string &s) {
    long long hash = 0;
    for (char c : s)
        hash = (hash * BASE + c) % MOD;
    return hash;
}

vector<int> rabin_karp(const string &text, const string &pattern) {
    int n = text.size(), m = pattern.size();
    if (m > n) return {};

    long long pattern_hash = poly_hash(pattern);
    long long hash = poly_hash(text.substr(0, m));
    long long power = 1;
    for (int i = 0; i < m - 1; ++i)
        power = power * BASE % MOD;

    vector<int> res;
    for (int i = 0; i <= n - m; ++i) {
        if (hash == pattern_hash && text.substr(i, m) == pattern)
            res.push_back(i);
        if (i + m < n) {
            hash = (hash - text[i] * power % MOD + MOD) % MOD;
            hash = (hash * BASE + text[i + m]) % MOD;
        }
    }
    return res;
}
