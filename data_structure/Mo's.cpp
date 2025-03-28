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

// Mo's Algorithm (오프라인 쿼리 최적화 기법)
// sqrt 분할 + 쿼리 정렬 후 양끝 이동
// 시간복잡도: O((N + Q) * sqrt(N))

struct Query {
    int l, r, idx;
    bool operator<(const Query &q) const {
        int block = l / block_size;
        int q_block = q.l / block_size;
        return block != q_block ? block < q_block : (block & 1 ? r < q.r : r > q.r);
    }
};

int block_size;
vector<int> mo_algorithm(vector<int> &a, vector<Query> &queries) {
    int n = a.size();
    block_size = sqrt(n);
    sort(queries.begin(), queries.end());

    int l = 0, r = -1;
    vector<int> res(queries.size());
    int current_answer = 0;

    auto add = [&](int x) {
        // a[x] 추가
    };
    auto remove = [&](int x) {
        // a[x] 제거
    };

    for (auto &q : queries) {
        while (l > q.l) add(--l);
        while (r < q.r) add(++r);
        while (l < q.l) remove(l++);
        while (r > q.r) remove(r--);
        res[q.idx] = current_answer;
    }
    return res;
}
