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
    
    int a, b;
    cin >> a >> b;

    int sub = b&1LL;
    b %= MOD;
    int E = b;
    for (int d=2; d*d<=a; ++d) {
        int cur = 0;
        while (a%d == 0) {
            ++cur;
            a /= d;
        }
        if (cur&1) sub = 0;
        E = E * (cur*b%MOD+1) % MOD;
    }
    if (a > 1) {
        E = E * (b+1) % MOD;
        sub = 0;
    }
    cout << (E+MOD-sub) % MOD * inv(2) % MOD;
}