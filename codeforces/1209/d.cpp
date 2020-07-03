#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define tiiii tuple<int,int,int,int>
#define popcount __builtin_popcountll
 
const int INF = 1LL<<60;
const int MOD = 1000000007;
 
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
string to_string(string s) {return s;}
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
    RREP(i, d-1, -1) result[d-1-i] = '0'+((x&1LL<<i)!=0);
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

vb seen;
vector<vi> nodes;
void dfs(int u, int p=-1) {
    seen[u] = true;
    for (int v : nodes[u]) if (v!=p && !seen[v]) {
        dfs(v, u);
    }
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, k;
    cin >> n >> k;

    nodes.resize(n);
    REP(i, 0, k) {
        int a,b;
        cin >> a >> b;
        --a; --b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    seen.resize(n);
    int total=0;
    REP(i, 0, n) {
        if (nodes[i].empty()) seen[i] = true;
        else ++total;
    }

    int c=0;
    REP(i, 0, n) {
        if (!seen[i]) {
            ++c;
            dfs(i);
        }
    }
    cout << k-total+c;
}