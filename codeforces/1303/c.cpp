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
 
vb used(26);
vector<set<int>> adj(26);
void dfs(int u, int p=-1) {
    cout << (char)(u+'a');
    used[u] = true;
    for (int v : adj[u]) if (v != p) {
        dfs(v, u);
    }
}
 
main() {
    ios::sync_with_stdio(0), cin.tie(0);
 
    CASET {
        string s;
        cin >> s;
        int n = s.size();
        used.assign(26, {});
        adj.assign(26, {});
        FOR(i, 1, n-1) {
            adj[s[i]-'a'].insert(s[i-1]-'a');
            adj[s[i]-'a'].insert(s[i+1]-'a');
        }
        if (n == 1) {
            cout << "YES\n";
            cout << "abcdefghijklmnopqrstuvwxyz\n";
            continue;
        }
        adj[s[0]-'a'].insert(s[1]-'a');
        adj[s.back()-'a'].insert(s[n-2]-'a');
        int ones = 0;
        int oneloc;
        bool failed = false;
        FOR(i, 0, 26) {
            if (adj[i].size() == 1) {
                ++ones;
                oneloc = i;
            }
            else if (adj[i].size() >= 3) {
                cout << "NO\n";
                failed = true;
                break;
            }
        }
        if (failed) continue;
        if (ones != 2) {
            cout << "NO\n";
            failed = true;
        }
        if (failed) continue;
        cout << "YES\n";
        dfs(oneloc);
        FOR(i, 0, 26) if (!used[i]) cout << (char)(i+'a');
        cout << '\n';
    }
}