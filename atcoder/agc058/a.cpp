#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi a(2*n);
    FOR(i, 0, 2*n) cin >> a[i];

    vi res;
    auto myswap = [&](int l, int r) {
        res.push_back(l+1);
        swap(a[l], a[r]);
    };

    FOR(i, 0, n-1) {
        if (a[2*i] < a[2*i+1]) {
            if (a[2*i+1] < a[2*i+2]) myswap(2*i+1, 2*i+2);
        }
        else {
            // a[2*i] > a[2*i+1]
            if (a[2*i] > a[2*i+2]) myswap(2*i, 2*i+1);
            else myswap(2*i+1, 2*i+2);
        }
    }
    if (a[2*n-2] > a[2*n-1]) myswap(2*n-2, 2*n-1);
    cout << res.size() << '\n';
    for (int i : res) cout << i << ' ';
}