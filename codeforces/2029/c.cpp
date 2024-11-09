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
        FOR(i, 0, n) cin >> a[i];

        vi udp(n+1);
        FOR(i, 1, n+1) {
            udp[i] = udp[i-1];
            if (udp[i] > a[i-1]) --udp[i];
            else if (udp[i] < a[i-1]) ++udp[i];
        }
        
        vi pref(n+1);
        FOR(i, 1, n+1) pref[i] = max(udp[i], pref[i-1]);

        vi sdp(n+1);
        sdp[0] = -1e9;
        sdp[1] = 0;
        FOR(i, 1, n+1) {
            int cur = sdp[i-1];
            if (cur > a[i-1]) --cur;
            else if (cur < a[i-1]) ++cur;
            sdp[i] = max(cur, pref[i-1]);
        }
        
        cout << sdp[n] << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}