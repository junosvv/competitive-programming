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

        if (n==3) cout << "NO\n";
        else {
            cout << "YES\n";
            if (n&1) {
                FOR(i, 0, n>>1) cout << (n>>1)-1 << ' ' << -(n>>1) << ' ';
                cout << (n>>1)-1;
            } else {
                FOR(i, 0, n>>1) cout << "1 -1 ";
            }
            cout << '\n';
        }
    }
}