#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 1e9 + 7;
int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1LL) res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
};
#define inv(x) powa(x, MOD-2)

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    const int BIG = 4e5;
    vi fact(BIG, 1);
    FOR(i, 1, BIG) fact[i] = i * fact[i-1] % MOD;
    vi cringe(BIG, 1);
    FOR(i, 1, BIG) cringe[i] = (4*i-2) * cringe[i-1] % MOD;

    auto solve = [&]() {
        int n, k;
        cin >> n >> k;
        FOR(i, 0, k) {
            int x, y;
            cin >> x >> y;
            if (x == y) --n;
            else n -= 2;
        }

        int res = 0;
        FOR(k, 0, n/2+1) {
            res = (res + fact[n] * inv(fact[2*k])%MOD * inv(fact[n-2*k])%MOD * cringe[k]%MOD) % MOD;
        }
        cout << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}