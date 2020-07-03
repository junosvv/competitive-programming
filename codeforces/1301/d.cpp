#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, b, a) for (int i=(b); i>(a); --i)
#define CASET int _T; cin >> _T; FOR(caset, 0, _T)
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vvi vector<vi>
#define vvb vector<vb>
#define pii pair<int,int>
#define t3i tuple<int,int,int>
#define mii map<int,int>
#define vpii vector<pii>
#define vt3i vector<t3i>
#define sq(x) (x)*(x)
#define inv(x) powa(x, MOD-2)
 
long long INF = 1LL<<60;
long long MOD = 1e9+7;
 
template <typename A, typename B> istream &operator>>(istream &is, pair<A, B> &pr) {is >> pr.first >> pr.second; return is;}
template <typename A> istream &operator>>(istream &is, vector<A> &v) {for (auto &x : v) is >> x; return is;}
ostream &operator<<(ostream &os, char &c) {os << (char)c; return os;}
ostream &operator<<(ostream &os, const char s[]) {os << (string)s; return os;}
ostream &operator<<(ostream &os, string &s) {for (char &c : s) os << (char)c; return os;}
template <typename A, typename B> ostream &operator<<(ostream &os, pair<A, B> &pr) {os << '(' << pr.first << ", " << pr.second << ')'; return os;}
ostream &operator<<(ostream &os, vb &v) {
    bool first = true;
    os << '[';
    for (const bool &x : v) {
        if (!first) os << ", ";
        first = false;
        os << x;
    }
    os << ']';
    return os;
}
template <class C> ostream &operator<<(ostream &os, C &v) {
    bool first = true;
    os << '[';
    for (auto &x : v) {
        if (!first) os << ", ";
        first = false;
        os << x;
    }
    os << ']';
    return os;
}
int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1) res = res*base % MOD;
        base = base*base % MOD;
        exp >>= 1;
    }
    return res;
}

int done = 0;
vector<pair<int, string>> res;
int R, C, K;

void check() {
    if (done == K) {
        vector<pair<int, string>> res0 = res;
        res.clear();
        FOR(i, 0, res0.size()) {
            if (res0[i].first) res.push_back(res0[i]);
        }
        cout << res.size() << '\n';
        for (auto pr : res) {
            cout << pr.first << ' ' << pr.second << '\n';
        }
        exit(0);
    }
}

main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> R >> C >> K;


    if (K > 4*R*C - 2*R - 2*C) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";

    FOR(x, 0, R-1) {
        res.push_back({1, "D"});
        ++done;
        check();
        if (done + C-1 >= K) {
            res.push_back({K-done, "R"});
            done = K;
            check();
        }
        res.push_back({C-1, "R"});
        done += C-1;
        if (done + C-1 >= K) {
            res.push_back({K-done, "L"});
            done = K;
            check();
        }
        res.push_back({C-1, "L"});
        done += C-1;
    }

    if (done + R-1 >= K) {
        res.push_back({K-done, "U"});
        done = K;
        check();
    }
    res.push_back({R-1, "U"});
    done += R-1;

    FOR(x, 0, C-1) {
        res.push_back({1, "R"});
        ++done;
        check();
        if (done + R-1 >= K) {
            res.push_back({K-done, "D"});
            done = K;
            check();
        }
        res.push_back({R-1, "D"});
        done += R-1;
        if (done + R-1 >= K) {
            res.push_back({K-done, "U"});
            done = K;
            check();
        }
        res.push_back({R-1, "U"});
        done += R-1;
    }

    if (done + C-1 >= K) {
        res.push_back({K-done, "L"});
        done = K;
        check();
    }
    res.push_back({R-1, "L"});
    done += R-1;
    check();
}