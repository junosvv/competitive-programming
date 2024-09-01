#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define t3i tuple<int,int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int n;
        cin >> n;
        vi a(n);
        vi seen(2);
        FOR(i, 0, n) {
            cin >> a[i];
            seen[a[i]&1LL] = 1;
        }

        if (seen[0] && seen[1]) {
            cout << "-1\n";
            return;
        }

        int mx = *max_element(a.begin(), a.end());
        vi res;
        while (mx) {
            if (mx == 1) {
                res.push_back(1);
                mx = 0;
                break;
            }
            res.push_back(mx/2);
            mx -= res.back();
        }
        assert(res.size() <= 40);
        cout << res.size() << '\n';
        for (int i : res) cout << i << ' ';
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}