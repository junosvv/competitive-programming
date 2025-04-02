#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vs vector<string>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<pii> points(k);
    FOR(i, 0, k) cin >> points[i].first >> points[i].second;
    points.emplace_back(n, 0);
    ++k;
    sort(points.begin(), points.end());

    vvi res;
    int px = 0, py = 0;
    FOR(i, 0, k) {
        int x = points[i].first, y = points[i].second;
        // cout << "at " << x << ' ' << y << ' ' << px << ' ' << py << '\n';
        if (px < x) {
            if (py == 0) {
                res.push_back({px, py, x-px, n});
            } else {
                if (n-py > 0) res.push_back({px, py, 1, n-py});
                if (x-px-1 > 0) res.push_back({px+1, 0, x-px-1, n});
            }
            if (y > 0) {
                res.push_back({x, 0, 1, y});
            }
        } else {
            // px == x
            if (py < y) {
                res.push_back({px, py, 1, y-py});
            }
        }
        px = x;
        py = y+1;
        if (py == n) {
            px = x+1;
            py = 0;
        }
    }
    cout << res.size() << '\n';
    for (vi aaa : res) {
        for (int i : aaa) cout << i << ' ';
        cout << '\n';
    }
}




// 101 6
// 0 0
// 100 100
// 0 100
// 100 0
// 50 50
// 1 0