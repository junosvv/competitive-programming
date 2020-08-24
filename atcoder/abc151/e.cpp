#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define CASET int _T; cin >> _T; REP(caset, 0, _T)
#define print(x) cout << to_string(x) << '\n'
#define vi vector<int>
#define vb vector<bool>
#define vs vector<string>
#define vvi vector<vi>
#define vvb vector<vb>
#define pii pair<int,int>
#define t3i tuple<int,int,int>
#define mii map<int,int>
#define sq(x) (x)*(x)
#define inv(x) powa(x, MOD-2)
 
int INF = 1LL<<60;
int MOD = 1e9+7;
 
string to_string(char &c) {string x(1, c); return x;}
string to_string(string &s) {return s;}
string to_string(const char s[]) {return (string)s;}
template <class C> string to_string(C &v) {
    string res;
    for (auto &x : v) res += to_string(x) + ' ';
    return res;
}
template <typename A> istream &operator>>(istream &is, vector<A> &v) {
    for (auto &x : v) is >> x;
    return is;
}
template <typename A, typename B> ostream &operator<<(ostream &os, pair<A, B> pr) {
    os << '(' << pr.first << ", " << pr.second << ')';
    return os;
}
ostream &operator<<(ostream &os, char &c) {os << (char)c; return os;}
ostream &operator<<(ostream &os, string &s) {for (char &c : s) os << (char)c; return os;}
ostream &operator<<(ostream &os, const char s[]) {os << (string)s; return os;}
template <class Container> ostream &operator<<(ostream &os, Container &v) {
    bool first = true;
    os << '[';
    for (auto &x : v) {
        if (!first) os << ',' << ' ';
        first = false;
        os << x;
    }
    os << ']';
    return os;
}
string bin_string(int x) {
    const int d = 32;
    string res(d, ' ');
    REP(i, 0, d) res[d-1-i] = '0'+(x>>i & 1LL);
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

vi fact;
int nCk(int n, int k) {
    if (k<0||k>n) return 0;
    return fact[n]*inv(fact[k]) % MOD * inv(fact[n-k]) % MOD;
}
 
main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vi a(n);
    cin >> a;
    sort(a.rbegin(), a.rend());
    vi pref = a, suff=a;
    REP(i, 1, n) pref[i] = (pref[i]+pref[i-1]) % MOD;
    RREP(i, n-2, -1) suff[i] = (suff[i]+suff[i+1]) % MOD;

    fact.resize(n+1); fact[0] = 1;
    REP(i, 1, n+1) fact[i] = i*fact[i-1] % MOD;

    int res = 0;
    REP(gap, k-2, n-1) {
        int temp = nCk(gap, k-2) * (pref[n-gap-2] - suff[gap+1] + MOD) % MOD;
        res = (res+temp) % MOD;
    }
    print(res);
}