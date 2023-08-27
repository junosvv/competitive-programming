#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vector<pii> a;
    FOR(i, 0, n) {
        int x;
        cin >> x;
        FOR(j, 0, x) a.emplace_back(i+1, j+1);
    }
    int m = a.size();
    cout << a[m/2].first << ' ' << a[m/2].second;
}