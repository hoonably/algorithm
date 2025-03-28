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

// Napsack (냅색 알고리즘)
// dp[j] : 총 넣은 무게가 j 이하일때 최대 가치합

int N, K;
int W[101], V[101], dp[100001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> N >> K;

    for (int i=0; i<N; i++){
        cin >> W[i] >> V[i];
    }

    for (int i=0; i<N; i++){
        int weight = W[i];
        // 이거 탑다운으로 안하면 같은 물건을 여러번 넣는 경우도 계산됨
        for (int j=K; j>=W[i]; j--){
            dp[j] = max(dp[j], dp[j-weight] + V[i]);
        }
    }

    cout << dp[K];
    
    return 0;
}