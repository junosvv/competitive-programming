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
    cin >> n;
    --n;

    int k = 1, m = 1;
    while (2*k <= n) {
        ++m;
        k *= 2;
    }

    cout << m << endl;
    FOR(i, 0, m) {
        vi res;
        FOR(j, 0, n+1) if (j>>i&1) res.push_back(j+1);
        cout << res.size() << ' ';
        for (int x : res) cout << x << ' ';
        cout << endl;
    }

    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    cout << 1 + stoi(s, nullptr, 2) << endl;
}