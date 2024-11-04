#include <bits/stdc++.h>
/*


*/

const int SZ = 10;

class DisjointSet {
private:
	vector<int> parent;
public:
	DisjointSet(int n) {
		parent.resize(n+1);
		for (int i = 1; i <= n; i++) parent[i] = i;
	}
	int findRoot(int x) {
		if (x == parent[x]) return x;
		return (parent[x] = findRoot(parent[x]));
	}
	void Union(int x, int y) {
		parent[findRoot(x)] = findRoot(y);
	}
	bool isSameGroup(int x, int y) {
		return (findRoot(x) == findRoot(y));
	}
};

int main() {
	DisjointSet s(5);
	s.Union(1, 2);
	s.Union(4, 5);
	s.Union(1, 4);
	s.isSameGroup(1, 3) ? cout << "YES\n" : cout << "NO\n";
	s.isSameGroup(2, 4) ? cout << "YES\n" : cout << "NO\n";
}