#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

vi get_z(string s) {
    int n = s.size();
    vi z(n);
    int l = 0, r = 0;
    FOR(i, 1, n) {
        z[i] = max(0LL, min(z[i-l], r-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            l = i;
            r = i + z[i]++;
        }
    }
    return z;
}


signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        string s;
        cin >> s;
        int n = s.size();

        vi next(n, n);
        ROF(i, n-2, -1) {
            if (s[i+1] != 'a') next[i] = i+1;
            else next[i] = next[i+1];
        }

        FOR(i, 0, n) if (s[i] != 'a') {
            vi z = get_z(s.substr(i));
            int res = 0;
            FOR(j, i, n) {
                int mn = i;
                int k = j;
                bool fail = false;
                while (next[k] < n) {
                    mn = min(mn, next[k]-k-1);
                    k = next[k];
                    if (z[k-i] < j-i+1) {
                        fail = true;
                        break;
                    }
                    k += j-i;
                }
                if (fail) continue;
                res += mn+1;
            }
            cout << res << '\n';
            return;
        }
        cout << n-1 << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}