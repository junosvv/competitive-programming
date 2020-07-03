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

int n;
vi a;
pii solve(int check) {
    int L = 0, R = 1e9;
    FOR(i, 1, n) {
        if (a[i-1] == -1 && a[i] != -1) {
            L = max(L, a[i] - check);
            R = min(R, a[i] + check);
        }
        if (a[i] == -1 && a[i-1] != -1) {
            L = max(L, a[i-1] - check);
            R = min(R, a[i-1] + check);
        }
    }
    return {L, R};
}

main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    CASET {
        cin >> n;
        a.assign(n, {});
        cin >> a;

        int upp = 1e9+5;
        int k = upp;
        for (int b=upp; b>=1; b/=2) {
            while (k-b >= 0) {
                int L, R;
                tie(L, R) = solve(k-b);
                if (L > R) break;
                k -= b;
            }
        }
        int L, R;
        tie(L, R) = solve(k);
        int bound = 0;
        FOR(i, 1, n) {
            if (a[i-1] != -1 && a[i] != -1) {
                bound = max(bound, abs(a[i-1]-a[i]));
            }
        }
        cout << max(k, bound) << ' ' << L << '\n';
    }
}