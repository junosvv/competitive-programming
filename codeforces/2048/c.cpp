#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto solve = [&]() {
        string s;
        cin >> s;
        int n = s.size();

        vi cur;
        int L = 0, R = 0;
        FOR(i, 0, n) {
            if (s[i] == '1') {
                cur.push_back(i);
            } else {
                L = 0;
                R = n-1-i;
                FOR(j, i+1, n) {
                    vi nxt;
                    for (int k : cur) {
                        if (s[j] != s[k+j-i]) nxt.push_back(k);
                    }
                    cur = nxt;
                    if (!cur.empty()) {
                        L = cur[0];
                        R = cur[0] + n-1-i;
                    }
                }
                break;
            }
        }
        cout << "1 " << n << ' ' << L+1 << ' ' << R+1 << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}