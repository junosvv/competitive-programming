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
    RREP(i, d-1, -1) result[d-1-i] = '0'+((x&1LL<<i)!=0);
    return result;
}

vi getZ(string s) {
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
    
    int n, m, k;
    cin >> n >> m >> k;
    vi a(n),b(n),c(n),perf(n+1),canuse(n+1);
    vector<pii> tosort(n);
    perf[0] = k;
    REP(i, 0, n) {
        cin >> a[i] >> b[i] >> c[i];
        perf[i+1] = perf[i] + b[i];
        tosort[i] = {c[i], i};
    }
    sort(tosort.rbegin(), tosort.rend());
    canuse[n] = INF;
    RREP(i, n-1, -1) {
        canuse[i] = min(perf[i]-a[i], canuse[i+1]);
    }
    vi whentocap(n);
    REP(i, 0, n) whentocap[i] = i;
    REP(i, 0, m) {
        int x,y;
        cin >> x >> y;
        --x; --y;
        whentocap[y] = max(whentocap[y], x);
    }
    // cout << "OUTPUT\n";
    if (canuse[0] < 0) cout << -1;
    else {
        int res = 0;
        for (auto pr : tosort) {
            int imp = pr.first; int ind = whentocap[pr.second];
            // cout << imp << ' ' << ind << '\n';
            if (canuse[ind+1]) {
                res += imp;
                REP(i, ind+1, n) --canuse[i];
                REP(i, 0, ind+1) canuse[i] = min(canuse[i], canuse[ind+1]);
            }
        }
        cout << res << '\n';
    }
}