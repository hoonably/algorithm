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

// 에라토스테네스의 체 (prime sieve)
// 시간복잡도: O(N loglogN)
vector<bool> sieve(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    return is_prime;
}

// 밀러-라빈 소수 판별 (확률적, 정확도 높음)
// 시간복잡도: O(k * log^3 N)
bool miller_rabin(long long n, int iter = 5) {
    if (n < 2) return false;
    if (n % 2 == 0) return n == 2;

    long long d = n - 1;
    int s = 0;
    while ((d & 1) == 0) d >>= 1, s++;

    auto check = [&](long long a) {
        long long x = mod_pow(a, d, n);
        if (x == 1 || x == n - 1) return true;
        for (int r = 1; r < s; ++r) {
            x = x * x % n;
            if (x == n - 1) return true;
        }
        return false;
    };

    vector<int> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    for (int a : bases) {
        if (a >= n) break;
        if (!check(a)) return false;
    }
    return true;
}

// Pollard's Rho (소인수 분해)
// 시간복잡도: 기대 O(N^0.25), 대회용으로 빠름
long long pollard_rho(long long n) {
    if (n % 2 == 0) return 2;
    long long x = rand() % (n - 2) + 2;
    long long y = x, c = rand() % (n - 1) + 1, d = 1;
    while (d == 1) {
        x = (mod_pow(x, 2, n) + c) % n;
        y = (mod_pow(y, 2, n) + c) % n;
        y = (mod_pow(y, 2, n) + c) % n;
        d = gcd(abs(x - y), n);
        if (d == n) return pollard_rho(n);
    }
    return d;
}
