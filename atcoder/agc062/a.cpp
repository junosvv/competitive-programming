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
    FOR(ti, 0, T) {
        int n;
        string s;
        cin >> n >> s;
        char res = 'A';
        FOR(i, 0, n) if (s[i] == 'B') res = 'B';
        FOR(i, 1, n) if (s[i-1] == 'B' && s[i] == 'A') res = 'A';
        cout << res << '\n';
    }
}