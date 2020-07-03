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
int MOD = 1e9+7;

string to_string(char &c) {string x(1, c); return x;}
string to_string(string &s) {return s;}
string to_string(const char s[]) {return (string)s;}
string to_string(vb &v) {
    string res;
    for (const bool &x : v) res += to_string(x) + ' ';
    return res;
}
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
ostream &operator<<(ostream &os, vb &v) {
    bool first = true;
    os << '[';
    for (const bool &x : v) {
        if (!first) os << ',' << ' ';
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

vi fact(21, 1);

int solve(vi &seq) {
    int n = seq.size();
    REP(i, 0, n) if (seq[i] > i+1) return 0;
    int res = 1;
    REP(i, 0, n-1) {
        int k = i;
        for (int b=n; b>=1; b/=2) {
            while (k+b<n && seq[k+b] <= i+1) k += b;
        }
        res *= k-i+1;
    }
    int prev = 0;
    REP(i, 1, n) if (seq[i] != seq[i-1]) {
        assert(i-prev < 21);
        res /= fact[i-prev];
        prev = i;
    }
    assert(n-prev < 21);
    res /= fact[n-prev];

    return res;
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    REP(i, 1, 21) fact[i] = i*fact[i-1];
    
    CASET {
        int x;
        cin >> x;
        vi seq;
        for (int i=2; x; ++i) {
            seq.push_back(x%i);
            x /= i;
        }
        sort(seq.begin(), seq.end());
        
        int res = solve(seq);
        if (!seq.front()) {
            seq.erase(seq.begin());
            res -= solve(seq);
        }
        print(max(0LL, res-1));
    }
}