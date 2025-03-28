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

// Binary Search (이분 탐색)
// 조건을 만족하는 가장 작은 값 (or 최대값)을 찾는 기본 템플릿
// 시간복잡도: O(log(range)) * check()

int binary_search_min(int lo, int hi, function<bool(int)> check) {
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;  // check(lo) == true 인 최소값
}

int binary_search_max(int lo, int hi, function<bool(int)> check) {
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (check(mid)) lo = mid;
        else hi = mid - 1;
    }
    return lo;  // check(lo) == true 인 최대값
}
