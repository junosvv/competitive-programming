#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, w;
    cin >> n >> w;
    vi alive(w, 1), height(w), a(n);
    int cntalive = w;
    FOR(i, 0, n) {
        cin >> a[i];
        --a[i];
    }

    FOR(i, 0, n) {
        if (alive[a[i]]) --cntalive;
        alive[a[i]] = 0;
        ++height[a[i]];
        
        int j = a[i];
        while (0 <= j-1 && j < w && alive[j-1] && !alive[j] && abs(height[j-1] - height[j]) <= 1) {
            alive[j] = 1;
            ++cntalive;
            ++j;
        }

        j = a[i];
        while (0 <= j && j+1 < w && alive[j+1] && !alive[j] && abs(height[j+1] - height[j]) <= 1) {
            alive[j] = 1;
            ++cntalive;
            --j;
        }

        if (cntalive == 0) {
            cout << i+1;
            exit(0);
        }
    }
    cout << n+1 << '\n';
}