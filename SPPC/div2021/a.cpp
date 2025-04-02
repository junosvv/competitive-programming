#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vector<string> x(n);
    vector<bool> y(n);
    int nos = 0;
    FOR(i, 0, n) {
        cin >> x[i];
        string s;
        cin >> s;
        y[i] = s == "yes";
        if (!y[i]) ++nos;
    }

    FOR(i, 0, n) {
        cout << x[i] << ' ' << (y[i] ? nos : 0) << '\n';
    }
}
