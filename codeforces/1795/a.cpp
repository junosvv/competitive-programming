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
        string s, t;
        cin >> s >> t;
        reverse(t.begin(), t.end());
        s += t;
        int res = 0;
        FOR(i, 1, n+m) if (s[i] == s[i-1]) ++res;
        if (res <= 1) cout << "YES\n";
        else cout << "NO\n";
    }
}