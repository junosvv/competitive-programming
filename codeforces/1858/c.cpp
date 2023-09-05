#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int T;
    cin >> T;
    FOR(t, 0, T) {
        int n;
        cin >> n;
        vi seen(n+1);
        vi res;
        ROF(i, n, 0) {
            int j = i;
            while (true) {
                if (!seen[j]) {
                    res.push_back(j);
                    seen[j] = true;
                }
                if (j&1) break;
                j /= 2;
            }
        }
        for (int i : res) cout << i << ' ';
        cout << '\n';
    }
}