#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    vi a(n);
    FOR(i, 0, n) {
        cin >> a[i];
        --a[i];
    }
 
    vi tree(2*n);
    FOR(i, 0, n) tree[n+i] = a[i];
    ROF(i, n-1, 0) tree[i] = min(tree[2*i], tree[2*i+1]);
 
    auto upd = [&](int x, int delta) {
        x += n;
        tree[x] = delta;
        x /= 2;
        while (x) {
            tree[x] = min(tree[2*x], tree[2*x+1]);
            x /= 2;
        }
    };
 
    auto query = [&](int l, int r) {
        l += n;
        r += n;
        int res = 1e9;
        while (l <= r) {
            if (l&1) res = min(res, tree[l++]);
            if (!(r&1)) res = min(res, tree[r--]);
            l /= 2;
            r /= 2;
        }
        return res;
    };
 
    vector<deque<int>> pos(m);
    FOR(i, 0, n) pos[a[i]].push_back(i);
    set<int> lasts;
    FOR(i, 0, m) lasts.insert(pos[i].back());
 
    int prev = 0;
    vi res;
    while (!lasts.empty()) {
        int x = *lasts.begin();
        int mn = query(prev, x);
        cout << mn+1 << ' ';
        for (int i : pos[mn]) upd(i, 1e9);
        lasts.erase(pos[mn].back());
        while (pos[mn][0] < prev) pos[mn].pop_front();
        prev = pos[mn][0] + 1;
    }
}