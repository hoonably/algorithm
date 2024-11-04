#include <bits/stdc++.h>
using namespace std;


// 2-SAT
struct TwoSat {
	int n, var;
	int vcnt;
	vector<int> v;
	vector<vector<int>> graph;  // 정방향 그래프
	vector<vector<int>> grev;  // 역방향 그래프

    TwoSat(int var_){ init(var_); }

	void init(int var_) {
		var = var_;
		n = var_ * 2;
		vcnt = 0;
		v.clear(); v.resize(n);
		graph.resize(n); grev.resize(n);
	}
	int negation(int nod) {
		return nod >= var ? nod - var : nod + var;
	}
	// p implies q. p -> q
	void add(int p, int q) {
		graph[p].push_back(q);
		graph[negation(q)].push_back(negation(p));
		grev[q].push_back(p);
		grev[negation(p)].push_back(negation(q));
	}
	// p or q
	void addCNF(int p, int q) {
		add(negation(p), q);  // !p -> q 사용
	}
	vector<int> emit;
	void dfs1(int nod) {  // 정방향 그래프 DFS
		v[nod] = vcnt;
		for (int next : graph[nod]) {
			if (v[next] == vcnt) continue;
			dfs1(next);
		}
		emit.push_back(nod);
	}
	void dfs2(int nod) {
		v[nod] = vcnt;
		for (int next : grev[nod]) {
			if (v[next] == vcnt) continue;
			dfs2(next);
		}
		emit.push_back(nod);
	}

	vector<int> scc_check;
	bool solve() {
		++vcnt;
		emit.clear();
		for (int i = 0; i < n; i++) {
			if (v[i] == vcnt) continue;
			dfs1(i);
		}
		++vcnt;
		scc_check.resize(n);
		int scc_index = 0;
		for (auto start : vector<int>(emit.rbegin(), emit.rend())) {  // 역방향 iterator rbegin, rend
			if (v[start] == vcnt) continue;
			emit.clear();
			dfs2(start);
			++scc_index;
			for (auto node : emit) {
				scc_check[node] = scc_index;
				// 같은 SCC에 p와 !p가 모두 참 => 불가능
				if (scc_check[negation(node)] == scc_index) return false;
			}
		}
		return true;
	}
	bool is_true(int idx){  // 위상 정렬 순서가 더 빠른게 참
		return scc_check[idx] > scc_check[negation(idx)];
	}
};