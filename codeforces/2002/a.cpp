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
        int a, b, c;
        cin >> a >> b >> c;
        a = min(a, c);
        b = min(b, c);
        cout << a*b << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}