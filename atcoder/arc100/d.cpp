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
bool mini(int &a, int b) { return b < a ? a = b, 1 : 0; }
bool maxi(int &a, int b) { return b > a ? a = b, 1 : 0; }

main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vi a(n);
    cin >> a;
    vi pref = a, suff = a;
    FOR(i, 1, n) pref[i] += pref[i-1];
    ROF(i, n-2, -1) suff[i] += suff[i+1];

    vi prefs(n), suffs(n);
    int h = 0;
    FOR(i, 1, n) {
        while (h<n-1 && abs(pref[h+1] - pref[i]/2) < abs(pref[h] - pref[i]/2)) ++h;
        prefs[i] = min(pref[h], pref[i] - pref[h]);
    }
    h = n-1;
    ROF(i, n-2, -1) {
        while (h>0 && abs(suff[h-1] - suff[i]/2) < abs(suff[h] - suff[i]/2)) --h;
        suffs[i] = min(suff[h], suff[i] - suff[h]);
    }
    
    int res = INF;
    FOR(i, 2, n-1) {
        vi vals = {prefs[i-1], pref[i-1] - prefs[i-1], suffs[i], suff[i] - suffs[i]};
        mini(res, *max_element(vals.begin(), vals.end()) - *min_element(vals.begin(), vals.end()));
    }
    cout << res;
}