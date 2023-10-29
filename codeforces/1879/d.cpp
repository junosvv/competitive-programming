#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 998244353;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];

    int res = 0;
    FOR(k, 0, 32) {
        int cur = 0;
        int even = 0, odd = 0, evencnt = 0, oddcnt = 0;
        FOR(i, 0, n) {
            ++evencnt;
            even += evencnt;
            odd += oddcnt;
            if (a[i]>>k&1LL) {
                swap(evencnt, oddcnt);
                swap(even, odd);
            }
            cur += odd;
        }
        res = (res + (1LL<<k)%MOD * (cur%MOD)) % MOD;
    }
    cout << res;
}