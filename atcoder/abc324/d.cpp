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
    string s;
    cin >> n >> s;
    sort(s.begin(), s.end());

    int res = 0;
    for (int i=0; i*i<=1e14; i++) {
        string t = to_string(i*i);
        if (t.size() > n) break;
        t.resize(n, '0');
        sort(t.begin(), t.end());
        if (s == t) ++res;
    }
    cout << res;
}