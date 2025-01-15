#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();

    vi loc(26, -1);
    FOR(i, 1, n) {
        if (loc[s[i]-'a'] == -1) loc[s[i]-'a'] = i;
    }

    int res = 1e9, key = -1;
    ROF(i, m-2, -1) {
        if (loc[t[i]-'a'] != -1) {
            int cur = m-i + loc[t[i]-'a'];
            if (cur < res) {
                res = cur;
                key = i;
            }
        }
    }
    if (key == -1) cout << "-1\n";
    else  cout << s.substr(0, loc[t[key]-'a']) << t.substr(key, m-key) << '\n';
}