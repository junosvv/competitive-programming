#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    int nodds = 0;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        a -= x/2;
        b -= x/2;
        c -= x/2;
        d -= x/2;
        if (x&1) ++nodds;
    }
    FOR(i, 0, nodds+1) {
        if (a <= i && i <= b && c <= nodds-i && nodds-i <= d) {
            cout << "Yes";
            exit(0);
        }
    }
    cout << "No";
}