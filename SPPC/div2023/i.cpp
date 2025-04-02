#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vs vector<string>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string s;
    cin >> s;
    int n = s.size();
    set<string> seen;    
    FOR(i, 0, n) if (s[i] == '1') {
        string t;
        FOR(j, i, min(n, i+20)) {
            t += s[j];
            seen.insert(t);
        }
    }

    // for (string k : seen) cout << k << ' ';
    // cout << '\n';
    
    FOR(mask, 1, 1LL<<20) {
        string x(20, '0');
        FOR(d, 0, 20) if (mask>>d&1LL) x[d] = '1';
        while (x.back() == '0') x.pop_back();
        reverse(x.begin(), x.end());
        // cout << "checking " << x << '\n';
        if (!seen.count(x)) {
            cout << x << '\n';
            break;
        }
    }
}