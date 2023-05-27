#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++(i))
#define vi vector<int>
#define vs vector<string>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    vs g(n);
    FOR(i, 0, n) cin >> g[i];
    sort(g.begin(), g.end());
    
    do {
        bool fail = false;
        FOR(i, 1, n) {
            int diff = 0;
            FOR(j, 0, m) if (g[i-1][j] != g[i][j]) ++diff;
            if (diff != 1) {
                fail = true;
                break;
            }
        }
        if (!fail) {
            cout << "Yes";
            exit(0);
        }
    } while (next_permutation(g.begin(), g.end()));
    cout << "No";
}