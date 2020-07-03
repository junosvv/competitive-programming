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
 
long long INF = 1LL<<60;
long long MOD = 998244353;

string to_string(char &c) {string x(1, c); return x;}
string to_string(const char s[]) {return (string)s;}
string to_string(string &s) {return s;}
string to_string(vb &v) {string res; for (const bool &x : v) res += to_string(x) + ' '; return res;}
template <class C> string to_string(C &v) {string res; for (auto &x : v) res += to_string(x) + ' '; return res;}
template <typename A, typename B> istream &operator>>(istream &is, pair<A, B> &pr) {is >> pr.first >> pr.second; return is;}
template <typename A> istream &operator>>(istream &is, vector<A> &v) {for (auto &x : v) is >> x; return is;}
ostream &operator<<(ostream &os, char &c) {os << (char)c; return os;}
ostream &operator<<(ostream &os, const char s[]) {os << (string)s; return os;}
ostream &operator<<(ostream &os, string &s) {for (char &c : s) os << (char)c; return os;}
template <typename A, typename B> ostream &operator<<(ostream &os, pair<A, B> pr) {os << '(' << pr.first << ", " << pr.second << ')'; return os;}
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

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    vs grid(n);
    cin >> grid;

    vvi dist(n, vi(n, -1));
    dist[0][0] = grid[0][0]!='a';
    int best = -1;
    vector<pii> DELTAS = {{1, 0}, {0, 1}};
    deque<t3i> q = {{dist[0][0], 0, 0}};
    while (!q.empty()) {
        int t, r, c; tie(t, r, c) = q.front();
        if (dist[r][c] <= k) best = max(best, r+c);
        q.pop_front();
        for (pii delta : DELTAS) {
            int rr = r+delta.first, cc = c+delta.second;
            if (0<=rr&&rr<n && 0<=cc&&cc<n && dist[rr][cc] == -1) {
                if (grid[rr][cc] == 'a') {
                    dist[rr][cc] = t;
                    q.push_front({t, rr, cc});
                } else {
                    dist[rr][cc] = t+1;
                    q.push_back({t+1, rr, cc});
                }
            }
        }
    }
    REP(_, 0, best+1) cout << 'a';
    vector<pii> curs;
    if (best==-1) {
        cout << grid[0][0];
        curs = {{0, 0}};
    } else {
        REP(r, 0, n) REP(c, 0, n) if (r+c==best && dist[r][c] == k) curs.push_back({r, c});
    }

    vvb seen(n, vb(n));
    while (!curs.empty()) {
        int bestchr = -1;
        vector<pii> bests;
        for (pii pr : curs) {
            int r, c; tie(r, c) = pr;
            for (pii delta : DELTAS) {
                int rr=r+delta.first, cc=c+delta.second;
                if (0<=rr&&rr<n && 0<=cc&&cc<n && !seen[rr][cc]) {
                    seen[rr][cc] = true;
                    if (bestchr == -1 || grid[rr][cc]-'a' < bestchr) {
                        bestchr = grid[rr][cc]-'a';
                        bests = {{rr, cc}};
                    } else if (grid[rr][cc]-'a' == bestchr) {
                        bests.push_back({rr, cc});
                    }
                }
            }
        }
        if (bestchr!=-1) cout << (char)(bestchr+'a');
        curs = bests;
    }
}
