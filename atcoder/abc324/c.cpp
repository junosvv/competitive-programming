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
    
    int n;
    string t;
    cin >> n >> t;
    vector<string> strings(n);
    FOR(i, 0, n) cin >> strings[i];

    vi res;
    auto check = [&](string s, string t) {
        FOR(j, 0, t.size()) {
            if (j >= s.size() || t[j] != s[j]) {
                return t == s.substr(0, j) + t[j] + s.substr(j, (int)s.size() - j);
            }
        }
    };

    FOR(i, 0, n) {
        string s = strings[i];
        if (s.size() == t.size()) {
            int diff = 0;
            FOR(j, 0, t.size()) if (s[j] != t[j]) ++diff;
            if (diff <= 1) res.push_back(i);
        }
        if (s.size() + 1 == t.size()) if (check(s, t)) res.push_back(i);
        if (s.size() == t.size() + 1) if (check(t, s)) res.push_back(i);
    }

    cout << res.size() << '\n';
    for (int i : res) cout << i+1 << ' ';
}