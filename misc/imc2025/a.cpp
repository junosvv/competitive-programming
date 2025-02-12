#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, k;
    cin >> n >> k;
    const int INF = 1e6+2;
    vi a(n), cnt(INF);
    FOR(i, 0, n) {
        cin >> a[i];
        ++cnt[a[i]];
    }

    for (int x : a) {
        if (0 <= k-x && k-x < INF && cnt[k-x] >= (x == k-x ? 2 : 1)) {
            cout << "YES\n" << x << ' ' << k-x << '\n';
            exit(0);
        }
    }
    cout << "NO\n";
}