#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    int res = 100;
    FOR(b, 2, 11) {
        int cur = 0;
        int n0 = n;
        while (n) {
            cur += n%b;
            n /= b;
        }
        res = min(res, cur);
        n = n0;
    }
    cout << res;
}