#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string s, t;
    cin >> s >> t;

    int h = 0, v = 0;
    for (char c : t) {
        if (c == 'r') {
            h ^= 1;
            v ^= 1;
        } else if (c == 'h') {
            h ^= 1;
        } else {
            v ^= 1;
        }
    }

    int n = s.size();
    if (v) {
        string ss = s;
        FOR(i, 0, n) {
            if (s[i] == 'b') ss[i] = 'p';
            else if (s[i] == 'd') ss[i] = 'q';
            else if (s[i] == 'p') ss[i] = 'b';
            else ss[i] = 'd';
        }
        s = ss;
    }
    if (h) {
        string ss = s;
        FOR(i, 0, n) {
            if (s[i] == 'b') ss[i] = 'd';
            else if (s[i] == 'd') ss[i] = 'b';
            else if (s[i] == 'p') ss[i] = 'q';
            else ss[i] = 'p';
        }
        reverse(ss.begin(), ss.end());
        s = ss;
    }
    cout << s << '\n';
}