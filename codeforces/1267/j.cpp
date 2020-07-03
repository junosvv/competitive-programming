#include <bits/stdc++.h>
using namespace std;

#define int long long
#define CASET int _T; cin >> _T; REP(caset, 0, _T)
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define sq(x) (x)*(x)
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>
#define t3i tuple<int,int,int>
#define t4i tuple<int,int,int,int>
#define mii map<int,int>

const int INF = 1LL<<60;
const int MOD = 998244353;

template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
string to_string(string s) {return s;}
string to_string(bool b) {return b?"true":"false";}
template <typename A, typename B>
string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ")";}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> t) { return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + ")";}
template <typename A>
string to_string(vector<A> v) {
    bool first = true;
    string result = "[";
    for (A i : v) {
        if (!first) result += ", ";
        first = false;
        result += to_string(i); 
    }
    return result + "]";
}
string bin_string(int x) {
    const int d = 32;
    string result(d, ' ');
    REP(i, 0, d) result[d-1-i] = '0'+(x>>i & 1LL);
    return result;
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

vector<vi> nodes;
vb seen;
void dfs(int u, int p=-1) {
    if (seen[u]) return;
    seen[u] = true;
    for (int v : nodes[u]) if (v!=p) {
        dfs(v, u);
    }
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    CASET {
        int n;
        cin >> n;
        vi occ(n+1);
        REP(i, 0, n) {
            int x;
            cin >> x;
            ++occ[x];
        }
        vi a;
        REP(i, 1, n+1) if (occ[i]) a.push_back(occ[i]);
        sort(a.begin(), a.end());
        int k = a.size();

        int res=INF;
        REP(s, 1, a[0]+2) {
            int cur=0;
            bool failed = false;
            REP(i, 0, k) {
                if ((a[i]+s-1)/s*(s-1) > a[i]) failed = true;
                cur += (a[i]+s-1)/s;
            }
            if (!failed) res = min(res, cur);
        }
        cout << res << '\n';
    }
}