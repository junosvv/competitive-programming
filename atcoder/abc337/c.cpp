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
    vi a(n), nxt(n+10, -1);
    FOR(i, 0, n) {
        cin >> a[i];
        ++a[i];
        nxt[a[i]] = i+2;
    }

    int u = 0;
    while (nxt[u] != -1) {
        u = nxt[u];
        cout << u-1 << ' ';
    }
}