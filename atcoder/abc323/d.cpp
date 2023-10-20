#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 998244353;
#define inv(x) powa(x, MOD-2)

int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1LL) res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}

signed main() {
    int n;
    cin >> n;
    map<int,int> mp;
    FOR(i, 0, n) {
        int u, v;
        cin >> u >> v;
        mp[u] = v;
    }

    int res = 0;
    while (!mp.empty()) {
        int u, v;
        tie(u, v) = *mp.begin();
        if (v&1LL) ++res;
        if (v >= 2) mp[2*u] += v/2;
        mp.erase(mp.begin());
    }
    cout << res;
}