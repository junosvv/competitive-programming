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
        vvi locs(n);
        FOR(i, 0, n) {
            cin >> a[i];
            locs[a[i]].push_back(i);
        }
        FOR(i, 0, n) sort(locs[i].begin(), locs[i].end());
        if (locs[0].size() >= 2) {
            cout << "NO\n";
            return;
        }
        
        set<int> st;
        auto check = [&](int i) {
            auto it = st.lower_bound(i);
            if (it != st.end()) {
                int j = *it;
                if (a[j] == a[i] - 1) return true;
            }

            it = st.lower_bound(i);
            if (it == st.begin()) return false;
            --it;
            int j = *it;
            if (a[j] == a[i] - 1) return true;
            return false;
        };

        FOR(x, 0, n) {
            if (x >= 1) {
                for (int i : locs[x]) {
                    if (!check(i)) {
                        cout << "NO\n";
                        return;
                    }
                }
            }
            for (int i : locs[x]) {
                st.insert(i);
            }
        }
        cout << "YES\n";
        return;
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}