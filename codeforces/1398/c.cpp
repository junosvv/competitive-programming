#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi a(n);
        FOR(i, 0, n) {
            char c;
            cin >> c;
            a[i] = c-'0';
        }

        vi b(n+1);
        FOR(i, 1, n+1) b[i] = b[i-1] + a[i-1] - 1;
        map<int,int> mp;
        int res = 0;
        FOR(i, 0, n+1) {
            if (mp.count(b[i])) res += mp[b[i]];
            else mp[b[i]] = 0;
            ++mp[b[i]];
        }
        cout << res << '\n';
    }
}