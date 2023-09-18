#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    string s;
    cin >> s;
    int n = s.size();

    auto isp = [&](int i, int j) {
        FOR(k, 0, j-i+1) if (s[i+k] != s[j-k]) return false;
        return true;
    };

    int res = 0;
    FOR(i, 0, n) FOR(j, i, n) {
        if (isp(i, j)) res = max(res, j-i+1);
    }
    cout << res;
}