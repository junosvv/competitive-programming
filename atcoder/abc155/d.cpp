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
    
    int n, bigk;
    cin >> n >> bigk;
 
    vi a(n);
    cin >> a;
 
    sort(a.begin(), a.end());
 
    int neg = 0, zero = 0, pos = 0;
    FOR(i, 0, n) {
        if (a[i] < 0) ++neg;
        else if (a[i] == 0) ++zero;
        else ++pos;
    }
 
    vi poss, negs;
    FOR(i, 0, n) {
        if (a[i] < 0) negs.push_back(-a[i]);
        else if (a[i] > 0) poss.push_back(a[i]);
    }
    sort(negs.begin(), negs.end());
    sort(poss.begin(), poss.end());
 
    auto solveneg = [&](int x) {
        int res = 0;
        FOR(i, 0, negs.size()) {
            int u = -1;
            for (int bb=poss.size(); bb>=1; bb/=2) {
                while (u+bb < poss.size() && poss[u+bb]*negs[i] > x) u += bb;
            }
            ++u;
            res += u;
        }
        return res;
    };
 
    auto solve2 = [&](int x, vi &arr) {
        int res = 0;
        FOR(i, 0, arr.size()) {
            int u = -1;
            for (int bb=i; bb>=1; bb/=2) {
                while (u+bb < i && arr[i]*arr[u+bb] < x) u += bb;
            }
            ++u;
            res += u;
        }
        return res;
    };
 
    auto solve = [&](int x) {
        return solve2(x, poss) + solve2(x, negs);
    };
 
    int cntneg = neg * pos;
    int cntzero = zero*(zero-1)/2 + zero*(pos+neg);
    int cntpos = neg*(neg-1)/2 + pos*(pos-1)/2;
    if (bigk <= cntneg) {
        reverse(poss.begin(), poss.end());
        int upp = 1e18+5;
        int k = -upp;
        for (int b=upp; b>=1; b/=2) {
            while (k+b<0) {
                int val = solveneg(-k-b);
                if (val >= bigk) break;
                k += b;
            }
        }
        cout << k << '\n';
    } else if (bigk <= cntneg + cntzero) {
        cout << 0 << '\n';
    } else {
        bigk -= cntneg + cntzero;
        int upp = 1e18+5;
        int k = -1;
        for (int b=upp; b>=1; b/=2) {
            while (k+b < upp) {
                int val = solve(k+b);
                if (val >= bigk) break;
                k += b;
            }
        }
        cout << k << '\n';
    }
}