#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<pii> pairs(n);
    int sm = 0;
    FOR(i, 0, n) {
        cin >> pairs[i].first >> pairs[i].second;
        sm += pairs[i].second;
    }

    if (sm <= k) {
        cout << 1;
        exit(0);
    }

    sort(pairs.begin(), pairs.end());

    FOR(i, 0, n) {
        int a, b;
        tie(a, b) = pairs[i];
        
        sm -= b;
        if (sm <= k) {
            cout << a+1;
            exit(0);
        }
    }
}