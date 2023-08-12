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

    vi dp(n), bag = {a[0]}, tot(n);
    dp[a[0]] = 1;
    tot[0] = 1;
    for (int i : dp) cout << i << ' ';
    cout << '\n';
    FOR(i, 1, n) {
        vi dp2(n);
        while (!bag.empty() && bag.back() < a[i]) bag.pop_back();
        int j = 0;
        if (!bag.empty()) j = ainv[bag.back()];
        else {
            dp2[a[i]] = 1;
            tot[i] = 1;
        }
        bag.push_back(a[i]);

        for (int k : bag) {
            dp2[k] += dp[k];
            tot[i] += dp[k];
        }

        FOR(k, j, i) {
            dp2[a[i]] += tot[k];
            tot[i] += tot[k];
        }

        dp = dp2;
        for (int i : dp) cout << i << ' ';
        cout << '\n';
    }
}