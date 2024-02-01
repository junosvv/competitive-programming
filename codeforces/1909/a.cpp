#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        int n;
        cin >> n;
        vi x(n), y(n);
        FOR(i, 0, n) cin >> x[i] >> y[i];
        int L = *min_element(x.begin(), x.end());
        int R = *max_element(x.begin(), x.end());
        int D = *min_element(y.begin(), y.end());
        int U = *max_element(y.begin(), y.end());
        if (L >= 0 || R <= 0 || D >= 0 || U <= 0) cout << "YES\n";
        else cout << "NO\n";
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}