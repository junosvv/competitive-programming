#include <bits/stdc++.h>
using namespace std;
 
#define lglg long long
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

int BIG = 200010;

int n;
vi treebal, lazybal, a, treeocc, treeL, treeR, treeres;
vector<set<int>> locs(BIG);
int mostocc(int l, int r) {
    int res = 0;
    l += n;
    r += n;
    while (l <= r) {
        if (l&1) res = max(res, treeocc[l++]);
        if (!(r&1)) res = max(res, treeocc[r--]);
        l /= 2;
        r /= 2;
    }
    return res;
}

void calcocc(int x) {
    treeocc[x] = max(treeocc[2*x], treeocc[2*x+1]);
}

void updocc(int x, int delta) {
    x += n;
    treeocc[x] += delta;
    x /= 2;
    while (x) {
        calcocc(x);
        x /= 2;
    }
}

void auxbal(int x, int delta) {
    treebal[x] += delta;
    if (x < n) lazybal[x] += delta;
}

void calcbal(int x) {
    treebal[x] = lazybal[x] + min(treebal[2*x], treebal[2*x+1]);
    treeR[x] = treebal[2*x] < treebal[2*x+1] ? treeR[2*x] : treeR[2*x+1];
    treeL[x] = treebal[2*x+1] < treebal[2*x] ? treeL[2*x+1] : treeL[2*x];
    if (treebal[2*x] < treebal[2*x+1]) treeres[x] = treeres[2*x];
    else if (treebal[2*x+1] < treebal[2*x]) treeres[x] = treeres[2*x+1];
    else treeres[x] = treeres[2*x] + treeres[2*x+1] + mostocc(treeR[2*x]+1, treeL[2*x+1]);
}

void fixbal(int x) {
    x /= 2;
    while (x) {
        calcbal(x);
        x /= 2;
    }
}

void updbal(int l, int r, int delta) {
    l += n;
    r += n;
    int l0 = l, r0 = r;
    while (l <= r) {
        if (l&1) auxbal(l++, delta);
        if (!(r&1)) auxbal(r--, delta);
        l /= 2;
        r /= 2;
    }
    fixbal(l0);
    fixbal(r0);
}

int getres() {
    return n - treeres[1] - mostocc(0, treeL[1]);
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int q;
    cin >> n >> q;
    int n0=n; n=1; while (n<n0) n*=2;
    for (auto &v : {&a, &lazybal}) (*v).resize(n);
    for (auto &v : {&treebal, &treeL, &treeR, &treeocc, &treeres}) (*v).resize(2*n);
    REP(i, 0, n0) cin >> a[i];

    REP(i, 0, n) {
        locs[a[i]].insert(i);
        treeL[n+i] = treeR[n+i] = i;
        treeres[n+i] = 0;
    }
    REP(i, 0, n) ++treeocc[n+*locs[a[i]].begin()];
    REP(i, 0, BIG) if (locs[i].size()) {
        ++treebal[n+*locs[i].begin()];
        --treebal[n+*locs[i].rbegin()];
    }
    REP(i, n+1, 2*n) treebal[i] += treebal[i-1];
    RREP(i, n-1, 0) calcocc(i);
    RREP(i, n-1, 0) calcbal(i);
    cout << getres() << '\n';

    REP(_, 0, q) {
        int i, x;
        cin >> i >> x;
        --i;
        int oldcnt = treeocc[n+*locs[a[i]].begin()];
        updocc(*locs[a[i]].begin(), -oldcnt);
        updbal(*locs[a[i]].begin(), n-1, -1);
        updbal(*locs[a[i]].rbegin(), n-1, 1);
        --oldcnt;
        locs[a[i]].erase(i);
        if (locs[a[i]].size()) {
            updocc(*locs[a[i]].begin(), oldcnt);
            updbal(*locs[a[i]].begin(), n-1, 1);
            updbal(*locs[a[i]].rbegin(), n-1, -1);
        }

        a[i] = x;
        
        oldcnt = 1;
        if (locs[a[i]].size()) {
            oldcnt = treeocc[n+*locs[a[i]].begin()];
            updocc(*locs[a[i]].begin(), -oldcnt);
            updbal(*locs[a[i]].begin(), n-1, -1);
            updbal(*locs[a[i]].rbegin(), n-1, 1);
            ++oldcnt;
        }
        locs[a[i]].insert(i);
        updocc(*locs[a[i]].begin(), oldcnt);
        updbal(*locs[a[i]].begin(), n-1, 1);
        updbal(*locs[a[i]].rbegin(), n-1, -1);

        cout << getres() << '\n';
    }
}