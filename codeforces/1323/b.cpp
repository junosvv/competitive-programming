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
#define sortv
 
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
bool mini(int &a, int b) { return b < a ? a = b, 1 : 0; }
bool maxi(int &a, int b) { return b > a ? a = b, 1 : 0; }
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n), b(m);
    cin >> a >> b;
    vi prefA = a, prefB = b;
    FOR(i, 1, n) prefA[i] += prefA[i-1];
    FOR(i, 1, m) prefB[i] += prefB[i-1];
 
    auto solve = [&](int d, int w) {
        int curA = 0, curB = 0;
        FOR(i, -1, n-d) {
            int sum = prefA[i+d] - (i==-1 ? 0 : prefA[i]);
            if (sum == d) ++curA;
        }
        FOR(i, -1, m-w) {
            int sum = prefB[i+w] - (i==-1 ? 0 : prefB[i]);
            if (sum == w) ++curB;
        }
        return curA * curB;
    };
 
    int res = 0;
    for (int d=1; d*d<=k; ++d) {
        if (k%d==0) {
            res += solve(d, k/d);
            if (d*d != k) res += solve(k/d, d);
        }
    }
    cout << res;
}
