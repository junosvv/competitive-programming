#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 998244353;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int T;
    cin >> T;
    FOR(ti, 0, T) {
        int n;
        cin >> n;
        vi s(n), e(n);
        FOR(i, 0, n) cin >> s[i] >> e[i];
        int mx = 0;
        FOR(i, 1, n) if (s[i] >= s[0]) mx = max(mx, e[i]);
        cout << (mx < e[0] ? s[0] : -1) << '\n';
    }
}