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

// 피보나치 수열 (O(logN) - 행렬 거듭제곱)
typedef vector<vector<long long>> matrix;
const int MOD = 1e9 + 7;

matrix mul(matrix &a, matrix &b) {
    matrix res(2, vector<long long>(2));
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                res[i][j] = (res[i][j] + a[i][k]*b[k][j]) % MOD;
    return res;
}

matrix pow(matrix base, long long exp) {
    matrix res = {{1, 0}, {0, 1}};
    while (exp) {
        if (exp & 1) res = mul(res, base);
        base = mul(base, base);
        exp >>= 1;
    }
    return res;
}

long long fibonacci(long long n) {
    if (n == 0) return 0;
    matrix base = {{1, 1}, {1, 0}};
    return pow(base, n-1)[0][0];
}
