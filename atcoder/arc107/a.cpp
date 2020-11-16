#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define lg long long
#define vi vector<int>
#define inv(x) powa(x, MOD-2)

template <class T> ostream& operator<<(ostream& os, vector<T>& x) {
    os << '[';
    bool first = true;
    for (T& i : x) {
        if (!first) os << ", ";
        first = false;
        os << i;
    }
    return os << ']';
}

lg MOD = 998244353;

lg powa(lg base, lg exp) {
    lg res = 1;
    while (exp) {
        if (exp&1) res = res*base % MOD;
        base = base*base % MOD;
        exp >>= 1;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    lg a, b, c;
    cin >> a >> b >> c;

    auto f = [&](lg x) {
        return x*(x+1) % MOD * inv(2) % MOD;
    };

    cout << f(a)*f(b) % MOD *f(c) % MOD << '\n';
}
