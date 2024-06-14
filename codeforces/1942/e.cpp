#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 998244353;
int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1) res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}
#define inv(x) powa(x, MOD-2)

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    const int BIG = 1e6+1;
    vi fact(BIG, 1);
    FOR(i, 1, BIG) fact[i] = i * fact[i-1] % MOD;

    auto choose = [&](int n, int k) {
        if (k < 0 || k > n) return 0LL;
        return fact[n] * inv(fact[k]) % MOD * inv(fact[n-k]) % MOD;
    };

    auto solve = [&]() {
        int l, n;
        cin >> l >> n;
        
        int res = 0;
        for (int k=0; l-n-2*k>=n; ++k) {
            res -= choose(n-1+k, n-1) * choose(l-n-2*k, n) % MOD;
            res = (res + MOD) % MOD;
        }
        res = 2 * (res + choose(l, 2*n)) % MOD;
        cout << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}