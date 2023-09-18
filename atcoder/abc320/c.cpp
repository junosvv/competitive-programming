#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int m;
    string a, b, c;
    cin >> m >> a >> b >> c;
    a = a+a+a;
    b = b+b+b;
    c = c+c+c;
    m = 3*m;

    int res = -1;
    FOR(i, 0, m) FOR(j, 0, m) FOR(k, 0, m) if (i != j && j != k && i != k && a[i] == b[j] && b[j] == c[k]) {
        int cur = max(i, max(j, k));
        if (res == -1 || cur < res) res = cur;
    }
    cout << res;
}