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
        int n, m;
        cin >> n >> m;

        multiset<int> a;
        int res = 0;
        FOR(i, 0, n) {
            int x;
            cin >> x;
            a.insert(x);
            res += x;
        }

        FOR(i, 0, m) {
            int x;
            cin >> x;
            res -= *a.begin();
            a.erase(a.begin());
            res += x;
            a.insert(x);
        }
        cout << res << '\n';
    }
}