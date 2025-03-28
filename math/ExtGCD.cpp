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

// 확장 유클리드 알고리즘
// ax + by = gcd(a, b) 를 만족하는 x, y 구함
// a와 m이 서로소일 때 mod 역원: x % m
// 시간복잡도: O(logN)

int ext_gcd(int a, int b, int &x, int &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    int d = ext_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int mod_inv(int a, int m) {
    int x, y;
    int g = ext_gcd(a, m, x, y);
    if (g != 1) return -1;  // 역원 없음
    return (x % m + m) % m;
}
