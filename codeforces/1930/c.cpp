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
        vi a(n);
        FOR(i, 0, n) {
            cin >> a[i];
            a[i] += i+1;
        }
        sort(a.rbegin(), a.rend());

        vi b;
        for (int u : a) {
            if (b.empty() || u < b.back()) {
                b.push_back(u);
            } else {
                b.push_back(b.back() - 1);
            }
        }
        for (int i : b) cout << i << ' ';
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}