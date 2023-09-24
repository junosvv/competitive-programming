#include <bits/stdc++.h>
using namespace std;

typedef long long lg;
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.size();

    bool res = true;
    FOR(i, 1, n) if (s[i-1] <= s[i]) res = false;
    cout << (res ? "Yes" : "No");
}