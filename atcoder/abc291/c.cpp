#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<pii> seen = {{0, 0}};
    int r = 0, c = 0;
    FOR(i, 0, n) {
        if (s[i] == 'R') ++c;
        if (s[i] == 'L') --c;
        if (s[i] == 'D') ++r;
        if (s[i] == 'U') --r;
        if (seen.count({r, c})) {
            cout << "Yes";
            exit(0);
        }
        seen.insert({r, c});
    }
    cout << "No";
}