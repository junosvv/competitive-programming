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

vector<vi> colour, nodes;

void dfs(int c, int d, int u, int p=-1, int a=-1, int b=-1) {
    if (a==-1 && b==-1) colour[c*3+d][u] = c;
    else if (b==-1) colour[c*3+d][u] = d;
    else colour[c*3+d][u] = 3-a-b;
    for (int v : nodes[u]) if (v != p) {
        dfs(c, d, v, u, colour[c*3+d][u], a);
    }
}
 
main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    vector<vi> cost(3, vi(n));
    colour.assign(9, vi(n));
    cin >> cost;
    nodes.resize(n);
    REP(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }
    REP(i, 0, n) if (nodes[i].size() > 2) {
        cout << -1;
        return 0;
    }
    int start;
    REP(i, 0, n) if (nodes[i].size() == 1) start = i;
    int best=-1, bestval=INF;
    REP(c, 0, 3) {
        REP(d, 0, 3) {
            if (c==d) continue;
            dfs(c, d, start);
            int res = 0;
            REP(i, 0, n) {
                res += cost[colour[c*3+d][i]][i];
            }
            if (res < bestval) {
                bestval = res;
                best = c*3+d;
            }
        }
    }
    cout << bestval << '\n';
    REP(i, 0, n) cout << 1+colour[best][i] << ' ';
}