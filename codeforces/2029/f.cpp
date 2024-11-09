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
        string s;
        cin >> s;

        int dupR = 0, dupB = 0;
        FOR(i, 0, n+1) {
            if (s[i] == 'R' && s[(i+1)%n] == 'R') ++dupR;
            if (s[i] == 'B' && s[(i+1)%n] == 'B') ++dupB;
        }
        if (dupR && dupB || !dupR && !dupB) {
            cout << "NO\n";
            return;
        }

        if (dupB) {
            FOR(i, 0, n) {
                if (s[i] == 'R') s[i] = 'B';
                else s[i] = 'R';
            }
        }

        string t(n, '.');
        FOR(i, 0, n) if (s[i] == 'B') {
            FOR(j, 0, n) {
                t[j] = s[(i+j)%n];
            }
            break;
        }
        vi comps = {1};
        FOR(i, 1, n) {
            if (t[i] != t[i-1]) comps.push_back(0);
            ++comps.back();
        }
        for (int& i : comps) i = i&1;
        if (comps.size() <= 2) {
            cout << "YES\n";
            return;
        }
        int cnt = 0;
        for (int i : comps) {
            if (i == 0) ++cnt;
        }
        if (cnt != 1) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}