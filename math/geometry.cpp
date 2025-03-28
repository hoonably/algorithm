// 개선된 기하 유틸리티 템플릿 (Geometry Utility Template)
#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
using point = pair<double, double>;
const double EPS = 1e-9;

// 입출력 오버로딩
istream& operator>>(istream& is, point& p) { return is >> p.X >> p.Y; }
ostream& operator<<(ostream& os, const point& p) { return os << p.X << " " << p.Y; }

// 연산자 오버로딩
point operator+(const point &a, const point &b) { return {a.X + b.X, a.Y + b.Y}; }
point operator-(const point &a, const point &b) { return {a.X - b.X, a.Y - b.Y}; }
point operator*(const point &a, double b) { return {a.X * b, a.Y * b}; }
point operator/(const point &a, double b) { return {a.X / b, a.Y / b}; }

// 벡터 연산
double dot(const point &a, const point &b) { return a.X * b.X + a.Y * b.Y; }
double cross(const point &a, const point &b) { return a.X * b.Y - a.Y * b.X; }
double norm(const point &a) { return a.X * a.X + a.Y * a.Y; }

double dist2(point a, point b) { return norm(a - b); }
double dist(point a, point b) { return sqrt(dist2(a, b)); }

int ccw(const point &a, const point &b, const point &c) {
    double res = cross(b - a, c - b);
    return (res > EPS) - (res < -EPS);
}

bool is_on_line(point a, point b, point p) {
    return ccw(a, b, p) == 0 && min(a, b) <= p && p <= max(a, b);
}

// 선분 교차
int is_cross(point s1, point e1, point s2, point e2) {
    int ab = ccw(s1, e1, s2) * ccw(s1, e1, e2);
    int cd = ccw(s2, e2, s1) * ccw(s2, e2, e1);
    if (ab < 0 && cd < 0) return -1;
    if (ab == 0 && cd == 0) {
        if (s1 > e1) swap(s1, e1);
        if (s2 > e2) swap(s2, e2);
        return s2 <= e1 && s1 <= e2;
    }
    return ab <= 0 && cd <= 0;
}

bool where_cross(point s1, point e1, point s2, point e2, point& res) {
    point d1 = e1 - s1, d2 = e2 - s2;
    double det = cross(d1, d2);
    if (abs(det) < EPS) return false;
    point diff = s2 - s1;
    double t = cross(diff, d2) / det;
    res = s1 + d1 * t;
    return true;
}

struct polygon {
    vector<point> dots;

    polygon(int N) { dots.resize(N); }
    polygon(vector<point> d) : dots(d) {}

    void build_convex_hull() {
        if (dots.size() < 3) return;
        swap(dots[0], *min_element(dots.begin(), dots.end()));
        sort(dots.begin() + 1, dots.end(), [&](const point &a, const point &b) {
            int o = ccw(dots[0], a, b);
            if (o) return o > 0;
            return dist2(dots[0], a) < dist2(dots[0], b);
        });
        vector<point> res;
        for (auto &p : dots) {
            while (res.size() >= 2 && ccw(res[res.size() - 2], res.back(), p) <= 0)
                res.pop_back();
            res.push_back(p);
        }
        dots = res;
    }

    int point_in_polygon(const point &p) {
        int cnt = 0, n = dots.size();
        point ray = {1e9, p.Y + 1};
        for (int i = 0; i < n; i++) {
            point a = dots[i], b = dots[(i + 1) % n];
            if (is_on_line(a, b, p)) return -1;
            if (is_cross(p, ray, a, b) == -1) cnt++;
        }
        return cnt % 2;
    }

    int point_in_convex(const point &p) {
        if (dots.size() < 3) return 0;
        if (ccw(dots[0], dots[1], p) < 0 || ccw(dots[0], dots.back(), p) > 0) return 0;
        if (ccw(dots[0], dots[1], p) == 0) return is_on_line(dots[0], dots[1], p) ? -1 : 0;
        if (ccw(dots[0], dots.back(), p) == 0) return is_on_line(dots[0], dots.back(), p) ? -1 : 0;

        int lo = 1, hi = dots.size() - 1;
        while (lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            if (ccw(dots[0], dots[mid], p) > 0) lo = mid;
            else hi = mid;
        }
        int pos = ccw(dots[lo], dots[hi], p);
        return pos == 0 ? -1 : pos > 0;
    }

    bool contain(polygon &other) {
        for (auto &p : other.dots)
            if (!point_in_convex(p)) return false;
        return true;
    }

    double rotating_calipers() {
        int n = dots.size();
        if (n < 2) return 0;
        int j = 1;
        double res = 0;
        for (int i = 0; i < n; ++i) {
            while (cross(dots[(i+1)%n] - dots[i], dots[(j+1)%n] - dots[j]) > 0)
                j = (j + 1) % n;
            res = max(res, dist(dots[i], dots[j]));
        }
        return res;
    }

    double area() {
        double res = 0;
        for (int i = 0; i < dots.size(); ++i) {
            point a = dots[i], b = dots[(i + 1) % dots.size()];
            res += cross(a, b);
        }
        return abs(res) / 2.0;
    }

    vector<pair<point, point>> make_lines() const {
        vector<pair<point, point>> res;
        for (int i = 0; i < dots.size(); ++i)
            res.emplace_back(dots[i], dots[(i + 1) % dots.size()]);
        return res;
    }
};
