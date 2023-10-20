#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define SQ(x) (x)*(x)


signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    function<double(double,double,double,double)> dist = [&](double x1, double y1, double x2, double y2) {
        return sqrt(SQ(x1-x2)+SQ(y1-y2));
    };

    auto solve = [&]() {
        double px, py, ax, ay, bx, by;
        cin >> px >> py >> ax >> ay >> bx >> by;

        double res = max(dist(ax, ay, 0.0, 0.0), dist(ax, ay, px, py));
        res = min(res, max(dist(bx, by, 0.0, 0.0), dist(bx, by, px, py)));
        res = min(res, max(dist(ax, ay, bx, by)/2, max(dist(ax, ay, 0.0, 0.0), dist(bx, by, px, py))));
        res = min(res, max(dist(ax, ay, bx, by)/2, max(dist(bx, by, 0.0, 0.0), dist(ax, ay, px, py))));
        cout << setprecision(15) << res << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}