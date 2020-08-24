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

vvi nxt;
bool solve2(string &s, string &t1, string &t2) {
    vvi dp(t1.size()+1, vi(t2.size()+1, INF));
    dp[0][0] = -1;
    FOR(i, 0, t1.size()+1) {
        FOR(j, 0, t2.size()+1) {
            if (i && dp[i-1][j]+1 < s.size()) dp[i][j] = min(dp[i][j], nxt[t1[i-1]-'a'][dp[i-1][j]+1]);
            if (j && dp[i][j-1]+1 < s.size()) dp[i][j] = min(dp[i][j], nxt[t2[j-1]-'a'][dp[i][j-1]+1]);
        }
    }
    return dp[t1.size()][t2.size()] < INF;
}

void solve() {
    string s, t;
    cin >> s >> t;

    nxt.assign(26, vi(s.size()));
    FOR(c, 0, 26) {
        ROF(i, s.size()-1, -1) {
            if (i == s.size()-1) {
                nxt[c][i] = INF;
            } else {
                nxt[c][i] = nxt[c][i+1];
            }
            if (s[i]-'a' == c) nxt[c][i] = i;
        }
    }

    FOR(i, 0, t.size()+1) {
        string t1 = t.substr(0, i);
        string t2 = t.substr(i);
        if (solve2(s, t1, t2)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

main() {
    ios::sync_with_stdio(0), cin.tie(0);
 
    CASET solve();
}