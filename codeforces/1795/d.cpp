#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define inv(x) powa(x, MOD-2)

const int MOD = 998244353;

int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    n /= 3;
    vi fact(n+1, 1);
    FOR(i, 1, n+1) fact[i] = i * fact[i-1] % MOD;
    int res = fact[n] * inv(fact[n/2]) % MOD * inv(fact[n/2]) % MOD;

    FOR(i, 0, n) {
        vi a(3);
        FOR(j, 0, 3) cin >> a[j];
        sort(a.rbegin(), a.rend());
        if (a[1] != a[2]) continue;
        if (a[0] != a[1]) res *= 2;
        else res *= 3;
        res %= MOD;
    }
    cout << res;
}