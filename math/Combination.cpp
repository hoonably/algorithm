#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii; typedef pair<ll,ll> pll; 
typedef tuple<int,int,int> tiii;
const int INF = 0x3f3f3f3f;  // 1061109567
// const ll INF = 0x3f3f3f3f3f3f3f3f;
// const int MOD = 1'000'000'007;
long long mod_pow(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
// --------------------------------------------------------------------

// 조합론 (팩토리얼, nCr, 페르마의 소정리 이용 역원)
// 전처리: O(N), 질의: O(1)
const int MOD = 1e9 + 7;
const int MAXN = 200005;
long long fac[MAXN], inv[MAXN];

void comb_init() {
    fac[0] = inv[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = mod_pow(fac[i], MOD - 2, MOD);  // 역원: 페르마
    }
}

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
}
