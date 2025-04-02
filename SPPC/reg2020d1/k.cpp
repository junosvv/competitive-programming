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
    
    int n;
    cin >> n;
    vi x(n), y(n);
    FOR(i, 0, n) cin >> x[i] >> y[i];

    auto dist = [&](int i, int j) {
        return SQ(x[i]-x[j])+SQ(y[i]-y[j]);
    };

    vi ignore(n, -1);
    while (true) {
        int mni=-1, mnj;
        FOR(i, 0, n) FOR(j, i+1, n) if (ignore[i] != j) {
            if (mni == -1 || dist(i, j) < dist(mni, mnj)) {
                mni = i;
                mnj = j;
            }
        }
        assert(mni != -1);
        if (ignore[mni] != -1 || ignore[mnj] != -1) {
            cout << dist(mni, mnj);
            break;
        }
        ignore[mni] = mnj;
        ignore[mnj] = mni;
    }
}