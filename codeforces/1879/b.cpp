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

    int T;
    cin >> T;
    FOR(ti, 0, T) {
        int n;
        cin >> n;
        vi a(n), b(n);
        FOR(i, 0, n) cin >> a[i];
        FOR(i, 0, n) cin >> b[i];
        int asum = accumulate(a.begin(), a.end(), 0LL);
        int bsum = accumulate(b.begin(), b.end(), 0LL);
        int amin = *min_element(a.begin(), a.end());
        int bmin = *min_element(b.begin(), b.end());

        cout << min(amin*n + bsum, bmin*n + asum) << '\n';
    }
}