#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAX 1'000'001

/*
세그먼트 트리
최솟값과 최댓값 구하기
pair 이용 first : 최소값, second : 최대값
*/

int N, M;
int arr[MAX];
vector<pii> segTree;

// 최소값, 최대값 트리 초기화
pii init(int node, int s, int e) {
    if (s == e)
        return segTree[node] = {arr[s], arr[s]};
    int mid = (s + e) / 2;
    auto l = init(node*2, s, mid);
    auto r = init(node*2 + 1, mid + 1, e);
    return segTree[node] = {min(l.first,r.first), max(l.second, r.second)};
}

// left ~ right 구간에서 최소값, 최대값을 pair로 반환
pii getMinMax(int node, int s, int e, int left, int right){
    if (left > e || right < s)
        return {1e9,0};  // 답에 영향을 받지 않는 값으로
    if (left <= s && right >= e)
        return segTree[node];
    int mid = (s + e) / 2;
    auto l = getMinMax(node*2, s, mid, left, right);
    auto r = getMinMax(node*2 + 1, mid + 1, e, left, right);
    return {min(l.first, r.first), max(l.second, r.second)};
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> M;

    // 트리의 크기
    int h = ceil(log2(N+1));  // ceil : 정수로 올림
    int treeSize = 1 << (h + 1);
    segTree.resize(treeSize);

    // arr[0]=0 으로 설정
    for (int i=1; i<=N; i++){
        cin >> arr[i];
    }

    // 트리 생성
    init(1, 1, N);

    for (int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        // a번째수 ~ b번째 수 최소 최대값 구하기
        auto temp = getMinMax(1, 1, N, a, b);
        cout << temp.first << ' ' << temp.second << "\n";
    }
    
    return 0;
}