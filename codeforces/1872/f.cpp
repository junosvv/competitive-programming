#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    auto solve = [&]() {
        int n;
        cin >> n;
        vi a(n), c(n), gone(n);
        vector<set<int>> GT(n);
        FOR(i, 0, n) {
            cin >> a[i];
            --a[i];
            GT[a[i]].insert(i);
        }
        FOR(i, 0, n) cin >> c[i];

        vi res;
        FOR(i, 0, n) {
            int j = i;
            while (!gone[j] && GT[j].empty()) {
                res.push_back(j);
                gone[j] = 1;
                GT[a[j]].erase(j);
                j = a[j];
            }
        }

        FOR(i, 0, n) if (!gone[i]) {
            gone[i] = 1;
            int mn = i;
            int j = a[i];
            while (j != i) {
                gone[j] = 1;
                if (c[j] < c[mn]) mn = j;
                j = a[j];
            }
            j = a[mn];
            while (j != mn) {
                res.push_back(j);
                j = a[j];
            }
            res.push_back(mn);
        }
        for (int i : res) cout << i+1 << ' ';
        cout << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}