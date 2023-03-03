#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

int solve(string a, string b) {
    int n = a.size();
    int res = 0;
    FOR(i, 0, n) if (a[i] != b[i]) ++res;
    return res;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;

        int acnt = 0, bcnt = 0;
        FOR(i, 0, n) {
            if (a[i] == '1') ++acnt;
            if (b[i] == '1') ++bcnt;
        }

        int res = 1e6;
        if (acnt == bcnt) {
            res = min(res, solve(a, b));
        }
        if (n-acnt+1 == bcnt) {
            bool first = true;
            FOR(i, 0, n) {
                if (a[i] == '1') {
                    if (b[i] == '1' && first) first = false;
                    else a[i] = '0';
                } else a[i] = '1';
            }
            res = min(res, 1 + solve(a, b));
        }
        if (res == 1e6) res = -1;
        cout << res << '\n';
    }
}