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
    vi a(n+1);
    FOR(i, 1, n+1) cin >> a[i];

    FOR(i, 1, n+1) {
        for (int j = i; j <= n; j += i) {
            a[i] = max(a[i], a[j]);
        }
    }

    sort(a.begin(), a.end());

    int res = 0, cur = 1;
    FOR(i, 1, n+1) {
        res = (res + cur * a[i]) % MOD;
        cur = cur * 2 % MOD;
    }
    cout << res;
}