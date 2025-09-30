#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, w;
    cin >> n >> w;
    vi a, b, c;
    FOR(i, 0, n) {
        char t;
        cin >> t;
        if (t == '!') {
            a.push_back(0);
            b.push_back(0);
            c.push_back(0);
            cin >> a.back() >> b.back() >> c.back();
        } else {
            int x;
            cin >> x;
            int res = 0;
            FOR(j, 0, a.size()) {
                if (a[j] <= x && x < a[j]+b[j] && (x-a[j]+1)&1LL) {
                    int y = (x-a[j]) / 2;
                    if (y&1LL) res -= c[j];
                    else res += c[j];
                }
            }
            cout << res << '\n';
        }
    }
}