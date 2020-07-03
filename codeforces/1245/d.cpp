#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, l, r) for (int i=(l); i<(r); ++i)
#define RFOR(i, r, l) for (int i=(r); i>(l); --i)
#define vi vector<int>
#define popcount __builtin_popcountll

const int INF = 1LL<<60;
const int MOD = 1000000007;

template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {
    return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> t) {
    return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + ")";
}

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
    const int d = 64;
    string result(d, ' ');
    RFOR(i, d-1, -1) result[d-1-i] = '0'+((x&1LL<<i)!=0);
    return result;
}

vector<int> getZ(string s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    FOR(i, 1, n) {
        z[i] = max(0LL, min(z[i-x], y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            x = i;
            y = i+z[i];
            ++z[i];
        }
    }
    return z;
}

int powa(int base, int exp) {
    if (exp<=0) return 1;
    if (base<=0) return 0;
    int val = powa(base, exp>>1);
    val = val*val % MOD;
    if (exp&1) {
        val = val*base % MOD;
    }
    return val;
}

vi par;

int find(int x) {
    int x0 = x;
    while (x != par[x]) x = par[x];
    while (x0 != x) {
        int y = par[x0];
        par[x0] = x;
        x0 = y;
    }
    return x;
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    vi x(n), y(n), c(n), k(n);
    FOR(i, 0, n) cin >> x[i] >> y[i];
    cin >> c >> k;
    FOR(i, 0, n) par.push_back(i);
    
    vector<tuple<int,int,int>> edges(n*(n-1)/2);
    int ii=0;
    FOR(a, 0, n) FOR(b, a+1, n) {
        edges[ii++] = {(k[a]+k[b])*(abs(x[a]-x[b])+abs(y[a]-y[b])), a, b};
    }
    sort(edges.begin(), edges.end());

    int yen = 0;
    vi connsA, connsB;
    vector<bool> stat(n, true);
    for (auto e : edges) {
        int cost, a, b;
        tie(cost, a, b) = e;
        int aStat = find(a);
        int bStat = find(b);
        if (aStat == bStat) continue;
        if (c[aStat] < c[bStat]) swap(aStat, bStat);
        if (c[aStat] > cost) {
            par[aStat] = bStat;
            stat[aStat] = false;
            yen += cost;
            connsA.push_back(a);
            connsB.push_back(b);
        }
    }
    
    int numStats = 0;
    bool any = false;
    FOR(x, 0, n) if (stat[x]) {
        yen += c[x];
        ++numStats;
        any = true;
    }
    cout << yen << '\n' << numStats << '\n';
    FOR(x, 0, n) if (stat[x]) cout << x+1 << '\n';
    if (any) cout << connsA.size() << '\n';
    FOR(x, 0, connsA.size()) cout << connsA[x]+1 << ' ' << connsB[x]+1 << '\n';
}