#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int,int> pii;
#define MAX

/*

*/

ll arr[MAX];
vector<ll> segTree;

// 최대값 트리 초기화
ll init(int node, int s, int e) {
    if (s == e)
        return segTree[node] = arr[s];
    int mid = (s + e) / 2;
    auto l = init(node*2, s, mid);
    auto r = init(node*2 + 1, mid + 1, e);
    return segTree[node] = max(l, r);
}

// idx 인덱스의 숫자를 value로 변화
void update(int node, int s, int e, int idx, ll value){
    if (idx < s || e < idx) return;
    if (s == e){
        segTree[node] = value;
        return;
    }
    int mid = (s + e) / 2;
    update(node * 2, s, mid, idx, value);
    update(node * 2 + 1, mid + 1, e, idx, value);
    segTree[node] = max(segTree[node * 2], segTree[node * 2 + 1]);
}

// left ~ right 구간에서 최대값을 ll로 반환
ll getMax(int node, int s, int e, int left, int right){
    if (left > e || right < s)
        return 0;  // 답에 영향을 받지 않는 값으로
    if (left <= s && right >= e)
        return segTree[node];
    int mid = (s + e) / 2;
    auto l = getMax(node*2, s, mid, left, right);
    auto r = getMax(node*2 + 1, mid + 1, e, left, right);
    return  max(l, r);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    
    
    return 0;
}