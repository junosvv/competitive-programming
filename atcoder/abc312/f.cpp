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
    vi take(1, 1e10), cans(1, 1e10), openers(1, 1e10);
    FOR(i, 0, n) {
        int t, x;
        cin >> t >> x;
        if (t == 0) take.push_back(x);
        if (t == 1) cans.push_back(x);
        if (t == 2) openers.push_back(x);
    }
    sort(take.begin(), take.end(), greater<int>()); take[0] = 0;
    sort(cans.begin(), cans.end(), greater<int>()); cans[0] = 0;
    sort(openers.begin(), openers.end(), greater<int>()); openers[0] = 0;
    FOR(i, 1, take.size()) take[i] += take[i-1];
    FOR(i, 1, openers.size()) openers[i] += openers[i-1];
    vi cans0 = cans;
    cans.clear();
    int k = 0;
    FOR(i, 0, cans0.size()) {
        if (i > openers[k]) {
            if (k+1 == openers.size()) break;
            ++k;
            cans.push_back(0);
        }
        cans.push_back(cans0[i]);
    }
    FOR(i, 1, cans.size()) cans[i] += cans[i-1];
    
    int res = 0;
    FOR(k, 0, m+1) {
        res = max(res, take[min((int)take.size()-1, k)] + cans[min((int)cans.size()-1, m-k)]);
    }
    cout << res;
}