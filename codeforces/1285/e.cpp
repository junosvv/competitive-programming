#include <bits/stdc++.h>
using namespace std;

#define int long long
#define CASET int _T; cin >> _T; REP(caset, 0, _T)
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
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
    for (auto &i : v) res += to_string(i) + ' ';
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
    
    CASET {
        int n;
        cin >> n;
        vector<t3i> events;
        REP(i, 0, n) {
            int l, r;
            cin >> l >> r;
            events.push_back({l, -1, i});
            events.push_back({r, 1, i});
        }
        sort(events.begin(), events.end());
        vi occ(n);
        set<int> curs;
        int prev = -1;
        bool added = false;
        for (t3i ev : events) {
            if (get<1>(ev) == -1) curs.insert(get<2>(ev));
            else curs.erase(get<2>(ev));
            if (curs.empty()) {
                if (added) --occ[prev];
                prev = -1;
                added = false;
            } else if (curs.size() == 1) {
                if (prev != -1) {
                    ++occ[*curs.begin()];
                    added = true;
                }
                prev = *curs.begin();
            }
        }
        int best = max_element(occ.begin(), occ.end())-occ.begin();
        if (occ[best] == 0) {
            best = -1;
            int res = 0;
            for (t3i ev : events) {
                if (get<1>(ev) == -1) curs.insert(get<2>(ev));
                else curs.erase(get<2>(ev));
                if (curs.empty()) ++res;
                if (curs.size() >= 2) best = *curs.begin();
            }
            if (best==-1) print(res-1);
            else print(res);
        } else {
            int res = 0;
            for (t3i ev : events) {
                if (get<2>(ev) == best) continue;
                if (get<1>(ev) == -1) curs.insert(get<2>(ev));
                else curs.erase(get<2>(ev));
                if (curs.empty()) ++res;
            }
            print(res);
        }
    }
}
