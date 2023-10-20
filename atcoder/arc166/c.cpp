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

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    vi fib(2e6+2, 1);
    FOR(i, 2, 2e6+2) fib[i] = (fib[i-1] + fib[i-2]) % MOD;
    vi pref(1e6+1, 1);
    FOR(i, 1, 1e6+1) pref[i] = fib[2*i] * pref[i-1] % MOD;

    int T;
    cin >> T;
    FOR(ti, 0, T) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);

        int res = pref[a] * pref[a] % MOD * powa(fib[2*a+1], b-a) % MOD;
        cout << res << '\n';
    }
}