#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi a(n), ainv(n);
    FOR(i, 0, n) {
        cin >> a[i];
        --a[i];
        ainv[a[i]] = i;
    }
    cout << '\n';

    set<vi> seen;
    function<void()> dfs = [&]() {
        seen.insert(a);
        FOR(i, 0, n-1) {
            int ai = a[i], ai1 = a[i+1];
            int mx = max(ai, ai1);
            a[i] = mx;
            a[i+1] = mx;
            if (!seen.count(a)) dfs();
            a[i] = ai;
            a[i+1] = ai1;
        }
    };
    dfs();
    cout << seen.size();
}