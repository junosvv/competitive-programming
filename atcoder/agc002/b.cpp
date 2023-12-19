#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vi cnt(n, 1);
    vi poss(n);
    poss[0] = 1;
    FOR(_, 0, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        
        --cnt[x];
        ++cnt[y];

        poss[y] |= poss[x];

        if (cnt[x] == 0) {
            poss[x] = 0;
        }
    }
    cout << accumulate(poss.begin(), poss.end(), 0LL);
}