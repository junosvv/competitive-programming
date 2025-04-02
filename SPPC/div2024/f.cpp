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
    const int BIG = 200005;
    vi ups(BIG, BIG), downs(BIG, -BIG);

    int xr = 0;
    FOR(i, 0, n) {
        char c;
        int x, y;
        cin >> c >> x >> y;
        if (c == 'U') {
            ups[x] = min(ups[x], y);
        } else {
            downs[x] = max(downs[x], y);
        }
        xr = max(xr, x+1);
    }

    vi res(xr), locs;
    int pos = 0;
    FOR(x, 1, xr) {
        res[x-1] = -1;
        locs.push_back(x-1);
        --pos;
        
        while (!locs.empty() && pos <= downs[x]) {
            res[locs.back()] = 1;
            locs.pop_back();
            pos += 2;
        }
        if (pos <= downs[x]) {
            cout << "Impossible";
            exit(0);
        }
    }

    pos = 0;
    FOR(x, 1, xr) {
        pos += res[x-1];
        if (pos >= ups[x]) {
            cout << "Impossible";
            exit(0);
        }
    }

    cout << "Possible\n";
    for (int i : res) cout << "-+"[i == 1];

    // int l = 0, r = 0;
    // FOR(x, 1, BIG) {
    //     --l;
    //     ++r;
    //     l = max(l, downs[x]+1);
    //     r = min(r, ups[x]-1);
    //     if ((l+x)&1LL) ++l;
    //     if ((r+x)&1LL) --r;
    //     if (l > r) {
    //         cout << "Impossible";
    //         exit(0);
    //     }
    // }
    
    // cout << "Possible\n";
}