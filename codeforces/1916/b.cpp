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
        int a, b;
        cin >> a >> b;
        if (b % a == 0) cout << b*b/a << '\n';
        else cout << a*b/__gcd(a,b) << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}