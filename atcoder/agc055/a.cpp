#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vs vector<string>
#define vb vector<bool>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vi res(3*n);
    vector<string> strings = {"ABC", "ACB", "BAC", "BCA", "CAB", "CBA"};
    FOR(t, 0, 6) {
        vi ix = {0, n, 2*n};
        bool stay = true;
        while (stay) {
            cout << ix[0] << ' ' << ix[1] << ' ' << ix[2] << endl;
            bool flag = true;
            FOR(i, 0, 3) {
                if (s[ix[i]] != strings[t][i]) {
                    while (s[ix[i]] < (i+1)*n && !res[ix[i]]) ++ix[i];
                    flag = false;
                    if (ix[i] >= (i+1)*n) stay = false;
                    break;
                }
            }
            if (flag) {
                cout << "Success!" << endl;
                FOR(i, 0, 3) res[ix[i]++] = t+1;
            }
        }
    }

    FOR(i, 0, 3*n) cout << res[i];
}