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
    FOR(i, 0, n) cin >> a[i];
    map<int,deque<int>> locs;
    FOR(i, 0, n) locs[a[i]].push_back(i);

    vi mintree(2*n), maxtree(2*n);
    FOR(i, 0, n) {
        mintree[n+i] = a[i];
        maxtree[n+i] = a[i];
    }
    ROF(x, n-1, 0) {
        mintree[x] = min(mintree[2*x], mintree[2*x+1]);
        maxtree[x] = max(maxtree[2*x], maxtree[2*x+1]);
    }
    
    auto updmin = [&](int x, int val) {
        x += n;
        mintree[x] = val;
        x /= 2;
        while (x) {
            mintree[x] = min(mintree[2*x], mintree[2*x+1]);
            x /= 2;
        }
    };
    auto updmax = [&](int x, int val) {
        x += n;
        maxtree[x] = val;
        x /= 2;
        while (x) {
            maxtree[x] = max(maxtree[2*x], maxtree[2*x+1]);
            x /= 2;
        }
    };
    auto querymin = [&](int l, int r) {
        l += n;
        r += n;
        int res = 1e9;
        while (l <= r) {
            if (l&1) res = min(res, mintree[l++]);
            if (!(r&1)) res = min(res, mintree[r--]);
            l /= 2;
            r /= 2;
        }
        return res;
    };
    auto querymax = [&](int l, int r) {
        l += n;
        r += n;
        int res = -1e9;
        while (l <= r) {
            if (l&1) res = max(res, maxtree[l++]);
            if (!(r&1)) res = max(res, maxtree[r--]);
            l /= 2;
            r /= 2;
        }
        return res;
    };

    int res = 0;
    while (true) {
        int x = querymin(0, n-1);
        if (x == 1e9) break;

        int i = locs[x].front();
        cout << "buying " << a[i] << endl;
        locs[x].pop_front();
        updmin(i, 1e9);
        updmax(i, -1e9);
        x = querymax(i+1, n-1);
        if (x == -1e9) continue;

        int j = locs[x].back();
        locs[x].pop_front();
        cout << "selling " << a[j] << endl;
        updmin(j, 1e9);
        updmax(j, -1e9);
        res += a[j] - a[i];
    }
    cout << res;
}