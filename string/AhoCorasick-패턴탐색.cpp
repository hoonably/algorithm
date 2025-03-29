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

// Aho-Corasick (다중 패턴 검색)
// 시간복잡도: O(N + M + 출력 개수)

struct TrieNode {
    map<char, TrieNode*> next;
    TrieNode *fail = nullptr;
    vector<int> output;
};

struct AhoCorasick {
    TrieNode *root;
    AhoCorasick() { root = new TrieNode(); }

    void insert(const string &word, int id) {
        TrieNode *cur = root;
        for (char c : word) {
            if (!cur->next[c]) cur->next[c] = new TrieNode();
            cur = cur->next[c];
        }
        cur->output.push_back(id);
    }

    void build() {
        queue<TrieNode*> q;
        root->fail = root;
        for (auto &[c, node] : root->next) {
            node->fail = root;
            q.push(node);
        }

        while (!q.empty()) {
            TrieNode *cur = q.front(); q.pop();
            for (auto &[c, nxt] : cur->next) {
                TrieNode *f = cur->fail;
                while (f != root && !f->next[c])
                    f = f->fail;
                if (f->next[c] && f->next[c] != nxt)
                    nxt->fail = f->next[c];
                else
                    nxt->fail = root;

                nxt->output.insert(nxt->output.end(),
                                   nxt->fail->output.begin(),
                                   nxt->fail->output.end());
                q.push(nxt);
            }
        }
    }

    vector<pair<int, int>> search(const string &text) {
        vector<pair<int, int>> result;
        TrieNode *cur = root;
        for (int i = 0; i < text.size(); ++i) {
            char c = text[i];
            while (cur != root && !cur->next[c])
                cur = cur->fail;
            if (cur->next[c]) cur = cur->next[c];

            for (int id : cur->output)
                result.emplace_back(i, id);  // 위치 i에서 id 패턴 발견
        }
        return result;
    }
};
