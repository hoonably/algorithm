// 📚 자주 쓰이는 C++ STL 및 함수 템플릿 정리
// Competitive Programming, Algorithm 대회용

#include <bits/stdc++.h>
using namespace std;

// ✅ Fast IO (입출력 빠르게)
void fastio() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// ✅ unordered_map / unordered_set
// 해시 기반, 평균 O(1), 최악 O(N). key 기반 빠른 탐색
unordered_map<string, int> ump;
unordered_set<int> uset;

// ✅ map / set
// 이진 트리 기반, 항상 정렬됨. O(logN)
map<int, int> mp;
set<string> s;


void temp(){
vector<int> v = {3, 1, 4, 1, 5, 9};

// ✅ vector 기본 정렬 (오름차순)
sort(v.begin(), v.end());
// ✅ custom sort (내림차순)
sort(v.begin(), v.end(), greater<>());

// ✅ lower_bound / upper_bound (이진 탐색 기반)
// 정렬된 배열에서 특정 값 이상 / 초과 위치 찾기
// 반환값은 iterator → 인덱스로 변환시 subtract 필요
int idx = lower_bound(v.begin(), v.end(), 10) - v.begin();
int idu = upper_bound(v.begin(), v.end(), 10) - v.begin();

// ✅ priority_queue (기본: 최대 힙)
priority_queue<int> pq_max;
priority_queue<int, vector<int>, greater<>> pq_min; // 최소 힙

// ✅ deque (양쪽 push/pop 가능)
deque<int> dq;
dq.push_back(1); dq.push_front(2);
dq.pop_back(); dq.pop_front();

// ✅ stack / queue
stack<int> st;
queue<int> q;

// ✅ bitset (비트 마스크 다루기 유용)
bitset<32> bits;
bits.set(1); bits.flip(2); bits.reset();

// ✅ pair / tuple
pair<int, int> p = {1, 2};
tuple<int, int, int> t = {1, 2, 3};
auto [x, y] = p; // C++17 구조 분해

// ✅ 문자열 to 숫자, 숫자 to 문자열
int x = stoi("123");
string s = to_string(456);

}

// ✅ 문자열 분할 (공백 기준)
vector<string> split(const string &s) {
    stringstream ss(s); string token;
    vector<string> res;
    while (ss >> token) res.push_back(token);
    return res;
}

// ✅ 문자열 분할 (구분자 기준)
vector<string> split(const string &s, char delim) {
    vector<string> res;
    stringstream ss(s); string token;
    while (getline(ss, token, delim)) res.push_back(token);
    return res;
}

// ✅ gcd / lcm
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

// ✅ 소수 판별 (기본)
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

// ✅ 해시 함수 커스텀 (pair<int, int> 용 unordered_map)
struct pair_hash {
    size_t operator()(const pair<int, int> &p) const {
        return hash<long long>()(((long long)p.first << 32) ^ p.second);
    }
};
unordered_map<pair<int, int>, int, pair_hash> hash_map;

// ✅ set에서 원소 지우기 (iterator 안전하게)
void erase_example(set<int> &s, int val) {
    auto it = s.find(val);
    if (it != s.end()) s.erase(it);
}


