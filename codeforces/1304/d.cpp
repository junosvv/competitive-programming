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

main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    CASET {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vi res(n+1);
        FOR(i, 0, n+1) res[i] = n-i;

        s += '>';

        int i=0, j=0;
        while (i < n+1 && j < n+1) {
            if (s[i] == '>') ++i;
            else if (j < i || s[j] == '<') ++j;
            else {
                reverse(res.begin()+i, res.begin()+j+1);
                i = j+1;
            }
        }

        FOR(i, 0, n) cout << res[i] << ' ';
        cout << '\n';
        
        s.pop_back();
        s += '<';

        res.assign(n+1, 0);
        FOR(i, 0, n+1) res[i] = i+1;

        i=0;
        j=0;
        while (i < n+1 && j < n+1) {
            if (s[i] == '<') ++i;
            else if (j < i || s[j] == '>') ++j;
            else {
                reverse(res.begin()+i, res.begin()+j+1);
                i = j+1;
            }
        }

        FOR(i, 0, n) cout << res[i] << ' ';
        cout << '\n';
    }
}