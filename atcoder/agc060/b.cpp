#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int _T;
    cin >> _T;
    FOR(_t, 0, _T) {
        int R, C, K;
        string s;
        cin >> R >> C >> K >> s;

        int res = 0;
        FOR(i, 1, R+C-2) {
            if (s[i] != s[i-1]) {
                ++res;
                ++i;
            }
        }
        if (K >= res) cout << "Yes\n";
        else cout << "No\n";
    }
}