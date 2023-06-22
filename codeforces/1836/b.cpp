#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int T;
    cin >> T;
    FOR(t, 0, T) {
        int n, k, g;
        cin >> n >> k >> g;

        int last = max(0LL, k*g - (g-1)/2 * (n-1));
        int r = last % g;
        last -= r;
        if (r >= (g+1)/2) last += g;

        cout << k*g - last << '\n';
    }
}