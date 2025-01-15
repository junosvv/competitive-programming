#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>
#define mii map<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    auto solve = [&]() {
        int l, r;
        cin >> l >> r;
        
        int offset = 0;
        ROF(d, 30, -1) {
            if ((l>>d&1LL) && (r>>d&1LL)) offset += 1LL<<d;
            else if ((l>>d&1LL) || (r>>d&1LL)) {
                int x = offset + (1LL<<d);
                int y = x - 1;
                int z = y-1 >= l ? y-1 : x+1;
                cout << x << ' ' << y << ' ' << z << '\n';
                break;
            }
        }
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}