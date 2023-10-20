#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

void mini(int& a, int b) {
    a = min(a, b);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi x(n+2), y(n+2);
    FOR(i, 1, n+1) cin >> x[i];
    FOR(i, 1, n+1) cin >> y[i];
    x[0] = -1e10;
    x[n+1] = 1e10;

    vector<pii> L, R;
    FOR(i, 1, n+2) {
        if (y[i] - y[i-1] > 0) {
            L.emplace_back(x[i-1] + 1, y[i] - y[i-1]);
        } else if (y[i] - y[i-1] < 0) {
            R.emplace_back(x[i] - 1, y[i-1] - y[i]);
        }
    }

    // for (pii pr : L) cout << pr.first << ", " << pr.second << " | ";
    // cout << '\n';
    // for (pii pr : R) cout << pr.first << ", " << pr.second << " | ";
    // cout << '\n';

    int i=0, j=0, pref_i=0, pref_j=0;
    int res = 1e10;
    while (i+1 < L.size() && j+1 < R.size()) {
        int new_i = pref_i + L[i].second;
        int new_j = pref_j + R[j].second;
        if (new_i <= new_j) {
            ++i;
            pref_i += L[i].second;
        }
        if (new_j <= new_i) {
            ++j;
            pref_j += R[j].second;
        }
        mini(res, R[j].first - L[i].first);
    }
    while (i+1 < L.size()) {
        ++i;
        mini(res, R[j].first - L[i].first);
    }
    while (j+1 < R.size()) {
        ++j;
        mini(res, R[j].first - L[i].first);
    }
    cout << (res >= 1e9+5 ? -1 : res);
}