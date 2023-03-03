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
        string s;
        cin >> s;

        int res = -1;
        FOR(i, 1, n) {
            if (s[i-1] == 'R' && s[i] == 'L') {
                res = 0;
                break;
            }
            if (s[i-1] == 'L' && s[i] == 'R') {
                res = i;
                break;
            }
        }
        cout << res << '\n';
    }
}