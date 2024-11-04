#include <bits/stdc++.h>
using namespace std;


// a -> b 이분 매칭
const int MAXA = 1001, MAXB = 1001;
struct Bipartite_match {
    vector<int> graph[MAXA];  // a -> b
    int grev[MAXB];  // b -> a (역방향)

    void add_edge(int a, int b) {
        graph[a].push_back(b);
    }

    bool visited[MAXA];  // a의 방문 여부
    bool dfs(int a) {  // a->b 매칭
        if (visited[a]) return false;
        visited[a] = true;
        for (int b : graph[a]) {
            // !grev[b] : 만약 매칭 안된 b의 정점이 있다면, 그 정점과 매칭
            // dfs(grev[b]) : dfs를 통해 다른 정점과 매칭
            if(!grev[b] || dfs(grev[b])) { 
                grev[b] = a;
                return true;
            }
        }
        return false;  // 매칭 불가
    }
    int match_count(int A) {  // 1~A 범위 매칭된거 카운트
        int ret = 0;
        for(int i = 1; i <= A; i++) {
            memset(visited, 0, sizeof(visited));
            if (dfs(i)) ret++;
        }
        return ret;
    }
}bm;