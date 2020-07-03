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
#define pii pair<int,int>
#define t3i tuple<int,int,int>
#define mii map<int,int>
#define sq(x) (x)*(x)
#define inv(x) powa(x, MOD-2)

int INF = 1LL<<60;
int MOD = 998244353;

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
ostream &operator<<(ostream &os, string &s) {for (char &c : s) os << (char)c; return os;}
ostream &operator<<(ostream &os, const char s[]) {os << (string)s; return os;}
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

    int x;
    cin >> x;
    if (x==1) {
        cout << "1 1\n";
        return 0;
    }
 
    mii primes;
    int x0 = x;
    for (int d=2; d*d<=x; ++d) {
        while (x%d==0) {
            ++primes[d];
            x /= d;
        }
    }
    if (x != 1) ++primes[x];
    
    x = x0;
    vi factors;
    for (int d=1; d*d<=x; ++d) {
        if (x%d==0) {
            factors.push_back(d);
        }
    }
    sort(factors.rbegin(), factors.rend());
 
    if (primes.size() == 1) {
        cout << 1 << ' ' << x << endl;
        return 0;
    }
    REP(i, 0, factors.size()) {
        mii prs;
        int y = factors[i];
        for (int d=2; d*d<=y; ++d) {
            while (y%d==0) {
                ++prs[d];
                y /= d;
            }
        }
        if (y>1) ++prs[y];
        bool failed = false;
        for (auto pr : prs) {
            if (pr.second != primes[pr.first]) failed = true;
        }
        if (!failed) {
            cout << factors[i] << ' ' << x/factors[i] << endl;
            break;
        }
    }
}
