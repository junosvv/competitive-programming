#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, q;
    string s;
    cin >> n >> s >> q;
    vi last(2, -1), t(q), x(q);
    string c(q, ' ');
    FOR(i, 0, q) {
        cin >> t[i] >> x[i] >> c[i];
        --x[i];
        if (t[i] != 1) last[t[i]-2] = i;
    }

    auto conv = [&](int i) {
        if (last[1] > last[0]) s[i] = toupper(s[i]);
        else s[i] = tolower(s[i]);
    };

    int m = max(last[0], last[1]);
    if (m != -1) FOR(i, 0, n) conv(i);
    FOR(i, 0, q) if (t[i] == 1) {
        s[x[i]] = c[i];
        if (i < m) conv(x[i]);
    }
    cout << s;
}