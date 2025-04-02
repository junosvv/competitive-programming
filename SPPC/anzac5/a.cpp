#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define lg long long

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vi res(5);
    FOR(i, 0, n) {
        string s;
        cin >> s;
        if (s == "M" || s == "L") ++res[0];
        else if (s == "S") ++res[3];
        else if (s == "X") ++res[4];
        else {
            int sz = stoi(s);
            if (sz >= 12) ++res[1];
            else ++ res[2];
        }
    }
    FOR(i, 0, 5) cout << res[i] << ' ';
}