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

// Segment Tree (세그먼트 트리)
// 구간합 / 구간최대 / 구간최소 등의 질의 + 업데이트 처리
// 시간복잡도: O(logN) per query / update

struct SegmentTree {
    int n;
    vector<long long> tree;

    SegmentTree(int size) {
        n = 1;
        while (n < size) n <<= 1;
        tree.resize(n * 2);
    }

    void update(int idx, long long val) {
        idx += n;
        tree[idx] = val;
        while (idx > 1) {
            idx >>= 1;
            tree[idx] = tree[idx*2] + tree[idx*2+1];
        }
    }

    long long query(int l, int r) { // [l, r)
        long long res = 0;
        l += n; r += n;
        while (l < r) {
            if (l & 1) res += tree[l++];
            if (r & 1) res += tree[--r];
            l >>= 1; r >>= 1;
        }
        return res;
    }
};
