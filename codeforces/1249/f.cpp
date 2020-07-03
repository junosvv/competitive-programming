#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define popcount __builtin_popcountll
 
const int INF = 1LL<<60;
const int MOD = 1000000007;
 
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
 
template <typename A>
string to_string(A x[], int n) {
    string result = "{";
    REP(i, 0, n) {
        if (i!=0) result += ", ";
        result += to_string(x[i]); 
    }
    return result + "}";
}
 
string bin_string(int x) {
    const int d = 64;
    string result(d, ' ');
    REP(i, d-1, -1) result[d-1-i] = '0'+((x&1LL<<i)!=0);
    return result;
}
 
vector<int> getZ(string s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    REP(i, 1, n) {
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

const int BIGN = 300; 
int weight[BIGN];
int n, k;
vector<int> nodes[BIGN];

vector<int> solve(int cur, int avoid) {
    vector<int> res(k);
    vector<vector<int>> prevs;
    for (int neighbour : nodes[cur]) if (neighbour != avoid) prevs.push_back(solve(neighbour, cur));

    RREP(d, k-1, 0) {
        int upp = prevs.size() <= 2 ? k-1 : (k-2)/2+1;
        int e=d-1;
        while (true) {
            int alt = max(d-1, k-2-e);
            if (prevs.size()>=3 && alt+alt+2<k) break;
            REP(elev, 0, prevs.size()) {
                int ans = 0;
                REP(neighbour, 0, prevs.size()) {
                    int oldans = ans;
                    if (neighbour == elev) ans += prevs[neighbour][e];
                    else ans += prevs[neighbour][alt];
                }
                res[d] = max(res[d], ans);
            }
            if (prevs.size() == 1 || alt == d-1) break;
            ++e;
        }
        if (d != k-1) res[d] = max(res[d], res[d+1]);
    }
    int ans=weight[cur];
    REP(neighbour, 0, prevs.size()) ans += prevs[neighbour][k-1];
    res[0] = max(res[1], ans);
    return res;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n >> k;
    REP(i, 1, n+1) cin >> weight[i];
    REP(i, 0, n-1) {
        int a, b;
        cin >> a >> b;
        nodes[a].push_back(b);
        nodes[b].push_back(a);
    }

    ++k;
    vector<int> res = solve(1, -1);
    cout << res[0];
}