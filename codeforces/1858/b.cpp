#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int T;
    cin >> T;
    FOR(t, 0, T) {
        int n, m, d;
        cin >> n >> m >> d;
        vi s(m+2, 1);
        FOR(i, 0, m) cin >> s[i+1];
        s[m+1] = n+1;

        vi a(m+2, 1), b(m+2);
        FOR(i, 1, m+2) a[i] = a[i-1] + (s[i] != s[i-1]) + (s[i] - s[i-1] - 1) / d;
        ROF(i, m, -1) b[i] = b[i+1] + (s[i+1] != s[i]) + (s[i+1] - s[i] - 1) / d;

        // for (int i : s) cout << i << ' ';
        // cout << '\n';
        // for (int i : a) cout << i << ' ';
        // cout << '\n';
        // for (int i : b) cout << i << ' ';
        // cout << '\n';

        vi res(m);
        FOR(i, 1, m+1) {
            // cout << i << ": " << a[i-1] << ' ' << b[i+1] << ' ' << "dist " << s[i+1] << " from " << s[i-1] << '\n';
            res[i-1] = a[i-1] + b[i+1] + (s[i+1] - s[i-1] - 1) / d;
        }
        int mn = *min_element(res.begin(), res.end());
        int cnt = 0;
        for (int i : res) if (i == mn) ++cnt;
        cout << mn << ' ' << cnt << '\n';
    }
}