#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi a(n);
    FOR(i, 0, n+1) {
        int cur = -1;
        FOR(j, 1, 10) {
            if (n%j == 0 && i % (n/j) == 0) {
                cur = j;
                break;
            }
        }
        if (cur == -1) cout << '-';
        else cout << cur;
    }
}