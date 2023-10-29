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

    int T;
    cin >> T;
    FOR(ti, 0, T) {
        string s;
        cin >> s;
        int n = s.size();
        s += '2';
        int prev = 0;
        int res1 = 0;
        int res2 = 1;
        int numcomps = 0;
        FOR(i, 1, n+1) {
            if (s[i] != s[i-1]) {
                res1 += i-prev-1;
                res2 = res2 * (i-prev) % MOD;
                prev = i;
                ++numcomps;
            }
        }
        FOR(j, 1, n-numcomps+1) res2 = res2 * j % MOD;
        cout << res1 << ' ' << res2 << '\n';
    }
}