#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define mii map<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vvi rects(n, vi(3));
    set<int> transinv;
    FOR(i, 0, n) {
        FOR(j, 0, 3) {
            cin >> rects[i][j];
            transinv.insert(rects[i][j]);
        }
    }
    int m = transinv.size();
    mii trans;
    int i = 0;
    for (int x : transinv) trans[x] = i++;
    FOR(i, 0, n) {
        FOR(j, 0, 3) rects[i][j] = trans[rects[i][j]];
        sort(rects[i].begin(), rects[i].end());
    }
    sort(rects.begin(), rects.end());

    vi tree(2*m, 1e9);
    auto upd = [&](int x, int val) {
        x += m;
        tree[x] = val;
        x /= 2;
        while (x) {
            tree[x] = min(tree[2*x], tree[2*x+1]);
            x /= 2;
        }
    };

    auto query = [&](int l, int r) {
        l += m;
        r += m;
        int res = 1e9;
        while (l <= r) {
            if (l&1) res = min(res, tree[l++]);
            if (!(r&1)) res = min(res, tree[r--]);
            l /= 2;
            r /= 2;
        }
        return res;
    };

    int j=0;
    bool res = false;
    FOR(i, 0, n) {
        if (rects[i][0] > rects[j][0]) {
            FOR(k, j, i) {
                if (rects[k][2] < tree[m+rects[k][1]]) {
                    upd(rects[k][1], rects[k][2]);
                }
            }
            j = i;
        }
        if (query(0, rects[i][1]-1) < rects[i][2]) {
            res = true;
            break;
        }
    }

    cout << (res ? "Yes" : "No");
}