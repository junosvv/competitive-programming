#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    auto solve = [&]() {
        int n, k;
        cin >> n >> k;
        vi types;
        int x = n;
        while (x) {
            types.push_back(x&1);
            x /= 2;
        }
        
        x = 0;
        int r = 0, m = 0;
        reverse(types.begin(), types.end());
        for (int t : types) {
            if (t) {
                if (2*r+1 >= k) {
                    x += x + (r+1)*(m+1);
                    m = 2*m+1;
                }
                r = 2*r+1;
            } else {
                if (2*r >= k) {
                    x += x + r*m;
                    m = 2*m;
                }
                r = 2*r;
            }
            // cout << "type " << t << '\n';
            // cout << x << ' ' << m << ' ' << r << '\n';
        }
        cout << x << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}