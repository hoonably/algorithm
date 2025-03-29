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

// check 함수를 사용해서 풀이
// int check(int k){
//     return ;
// }

// 일반 이분 탐색: target 값을 정확히 찾는 용도
// 반환값: target의 인덱스 or -1 (없으면)
int binary_search_exact(int lo, int hi, function<int(int)> check) {
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int res = check(mid);
        if (res == 0) return mid;
        else if (res < 0) lo = mid + 1;  // mid가 작다
        else hi = mid - 1;              // mid가 크다
    }
    return -1;
}

// 조건을 만족하는 "최소값"의 인덱스를 찾는 이분 탐색
// 반환값: check(lo) == 0인 최소 인덱스
int binary_search_min(int lo, int hi, function<int(int)> check) {
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        int res = check(mid);
        if (res <= 0) hi = mid;     // mid가 정답이거나 크다 → 왼쪽 탐색
        else lo = mid + 1;          // mid가 작다 → 오른쪽 탐색
    }
    return lo;
}

// 조건을 만족하는 "최대값"의 인덱스를 찾는 이분 탐색
// 반환값: check(lo) == 0인 최대 인덱스
int binary_search_max(int lo, int hi, function<int(int)> check) {
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        int res = check(mid);
        if (res >= 0) lo = mid;     // mid가 정답이거나 작다 → 오른쪽 탐색
        else hi = mid - 1;          // mid가 크다 → 왼쪽 탐색
    }
    return lo;
}
