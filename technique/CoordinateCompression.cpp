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

// Coordinate Compression (좌표 압축)
// 값의 상대 순서를 유지하면서 작은 수로 압축
// 시간복잡도: O(N logN)

void coordinate_compression(vector<int> &A) {
    vector<int> B = A;
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    for (int i = 0; i < A.size(); i++)
        A[i] = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
}
