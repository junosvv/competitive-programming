#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int L, g, R;
    cin >> L >> g >> R;
    vi t(R);
    FOR(i, 0, R) cin >> t[i];
    sort(t.begin(), t.end());

    FOR(k, 2, R+1) {
        if ((k-1)*g + (L-1)*t[0] >= L*t[k-1]) {
            cout << k-1;
            exit(0);
        }
        FOR(i, 1, k) if ((i-1)*g + L*t[k-i] >= i*g + L*t[k-i-1]) {
            cout << k-1;
            exit(0);
        }
    }
    cout << R;
}