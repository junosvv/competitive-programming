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

    auto solve = [&]() {
        int n;
        cin >> n;

        vi fact(n+1, 1), invfact(n+1, 1);
        FOR(i, 1, n+1) {
            fact[i] = i * fact[i-1] % MOD;
            invfact[i] = inv(i) * invfact[i-1] % MOD;
        }

        auto c = [&](int n, int k) {
            return fact[n] * invfact[k] % MOD * invfact[n-k] % MOD;
        };

        for (int k=1; 2*k+1 <= n; ++k) {
            int res = 0;
            for (int u=1; u*2*k+1 <= n; ++u) {
                res = (res + c(n, 2*k*u) - c(n-2*k*u+2*k-1, 2*k-1) + MOD) % MOD;
            }
            res = (res + 1) % MOD;
            cout << res << ' ';
        }
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}