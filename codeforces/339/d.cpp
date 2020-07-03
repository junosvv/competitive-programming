#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define popcount __builtin_popcountll

const int INF = 1LL<<60;
const int MOD = 998244353;

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
string to_string(A x[], signed n) {
    string result = "{";
    for (signed i=0; i<n; ++i) {
        if (i!=0) result += ", ";
        result += to_string(x[i]); 
    }
    return result + "}";
}

int powa(int base, int exp) {
    if (exp<=0) return 1;
    if (base<=0) return 0;
    int val = powa(base, exp/2);
    val = (val*val)%MOD;
    if (exp%2==1) {
        val *= base;
        val %= MOD;
    }
    return val;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    n = 1<<n;
    int a[2*n];
    REP(i, n, 2*n) cin >> a[i];

    bool usexor = false;
    RREP(i, n-1, 0) {
        if (usexor) a[i] = a[2*i]^a[2*i+1];
        else a[i] = a[2*i]|a[2*i+1];
        usexor ^= ((i&(i-1)) == 0);
    }

    REP(i, 0, m) {
        int q,b;
        cin >> q >> b;

        a[n+q-1] = b;
        int cur = (n+q-1)/2;
        bool usexor = false;
        while (cur) {
            if (usexor) a[cur] = a[2*cur]^a[2*cur+1];
            else a[cur] = a[2*cur]|a[2*cur+1];
            usexor = !usexor;
            cur /= 2;
        }
        cout << a[1] << '\n';
    }
}