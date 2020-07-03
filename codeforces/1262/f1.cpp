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

const int BIGN = 210000;
int fact[BIGN], invfact[BIGN];
int nCk(int n, int k) {
    if (k<0 || k>n) return 0;
    return fact[n]*invfact[k] % MOD*invfact[n-k] % MOD;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, k;
    cin >> n >> k;
    int oldh[n];
    REP(i, 0, n) cin >> oldh[i];
    if (k==1) cout << 0;
    else {
        vector<int> h;
        REP(i, 0, n) {
            if (oldh[i] != oldh[(i+1)%n]) h.push_back(oldh[i]);
        }
        int oldn = n;
        n = h.size();
        
        fact[0] = 1;
        REP(i, 1, BIGN) fact[i] = i*fact[i-1] % MOD;
        invfact[BIGN-1] = powa(fact[BIGN-1], MOD-2);
        RREP(i, BIGN-2, -1) invfact[i] = (i+1)*invfact[i+1] % MOD;

        int result = 0;
        REP(z, 0, n) {
            int val = nCk(n,z)*powa(k-2,z) % MOD;
            if ((n-z)%2==1) {
                val *= powa(2,n-z-1);
                val %= MOD;
            } else {
                int temp = (powa(2,n-z)+MOD-nCk(n-z,(n-z)/2)) % MOD;
                val *= temp;
                val %= MOD;
                val *= powa(2, MOD-2);
                val %= MOD;
            }
            result += val;
            result %= MOD;
        }
        result *= powa(k, oldn-n);
        result %= MOD;
        cout << result;
    }
}