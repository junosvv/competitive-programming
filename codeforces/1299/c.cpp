#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ld long double
# define PI 3.14159265358979323846
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, b, a) for (int i=(b); i>(a); --i)
#define CASET int _T; cin >> _T; REP(caset, 0, _T)
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
string bin_string(int x) {
    const int d = 32;
    string res(d, ' ');
    FOR(i, 0, d) res[d-1-i] = '0'+(x>>i & 1LL);
    return res;
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

main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi a(n);
    cin >> a;

    vi pref = a;
    FOR(i, 1, n) pref[i] += pref[i-1];

    int sum = 0;
    int len = 0;
    vpii res(n);
    vi inds;
    FOR(i, 0, n) {
        sum += a[i];
        ++len;
        if (i == n-1 || a[i+1] > a[i]) {
            while (inds.size() && res[inds.back()].first*len > sum*res[inds.back()].second) {
                sum += res[inds.back()].first;
                len += res[inds.back()].second;
                inds.pop_back();
            }
            res[i] = {sum, len};
            inds.push_back(i);
            sum = 0;
            len = 0;
        }
    }
    vector<ld> res2(n);
    res2[n-1] = (ld)res.back().first / res.back().second;
    ROF(i, n-2, -1) {
        res2[i] = min(res2[i+1], (ld)res[i].first / res[i].second);
    }
    for (ld i : res2) cout << setprecision(20) << i << '\n';
}