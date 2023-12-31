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
        string s;
        cin >> n >> s;
        s += '.'; ++n;

        set<char> st;
        int res = 0;
        FOR(i, 0, n) {
            res += st.size();
            st.insert(s[i]);
        }
        cout << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}