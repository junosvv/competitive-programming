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
        
        vi res(n+3);
        ROF(i, n-1, -1) {
            if (s[i] == '0') res[i] = res[i+1];
            else {
                res[i] = n-i + res[i+3];
            }
        }
        cout << accumulate(res.begin(), res.end(), 0LL) << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}