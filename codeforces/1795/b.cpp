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
        int n, x;
        cin >> n >> x;
        bool left = false, right = false;
        FOR(i, 0, n) {
            int l, r;
            cin >> l >> r;
            if (l == x) left = true;
            if (r == x) right = true;
        }
        cout << (left && right ? "YES\n" : "NO\n");
    }
}