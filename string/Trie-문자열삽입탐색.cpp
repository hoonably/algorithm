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

// Trie (문자열 삽입/탐색 자료구조)
// 시간복잡도: O(문자열 길이)

struct Trie {
    struct Node {
        map<char, Node*> next;
        bool terminal = false;
    };

    Node* root;

    Trie() { root = new Node(); }

    void insert(const string &s) {
        Node* cur = root;
        for (char c : s) {
            if (!cur->next[c]) cur->next[c] = new Node();
            cur = cur->next[c];
        }
        cur->terminal = true;
    }

    bool find(const string &s) {
        Node* cur = root;
        for (char c : s) {
            if (!cur->next[c]) return false;
            cur = cur->next[c];
        }
        return cur->terminal;
    }
};
