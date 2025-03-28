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

// Fenwick Tree (펜윅 트리, Binary Indexed Tree)
// 구간합, 포인트 업데이트에 특화된 자료구조
// 시간복잡도: O(logN) per query / update

struct Fenwick {
    vector<long long> bit;
    int n;
    Fenwick(int n) : n(n) { bit.assign(n+1, 0); }

    void add(int idx, long long val) {
        for (++idx; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    long long sum(int idx) { // [0..idx]
        long long res = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }

    long long range_sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};
