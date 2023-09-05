#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int T;
    cin >> T;
    FOR(t, 0, T) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c&1) {
            cout << (b > a ? "Second" : "First") << '\n';
        } else {
            cout << (a > b ? "First" : "Second") << '\n';
        }
    }
}