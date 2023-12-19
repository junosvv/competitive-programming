#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int N, X;
    cin >> N >> X;

    int res = N;
    int x = X, y = N-X;
    while (true) {
        if (x == y) {
            res += x;
            break;
        }
        if (x > y) swap(x, y);
        res += (y-1)/x * 2 * x;
        y %= x;
        if (y == 0) y = x;
    }
    cout << res;
}