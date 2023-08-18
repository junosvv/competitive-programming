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
    vi sz(n), best(37, 38);
    vvi win(37);
    FOR(i, 0, n) {
        cin >> sz[i];
        FOR(j, 0, sz[i]) {
            int x;
            cin >> x;
            win[x].push_back(i);
            best[x] = min(best[x], sz[i]);
        }
    }

    int x;
    cin >> x;
    vi res;
    for (int i : win[x]) if (sz[i] == best[x]) res.push_back(i+1);
    cout << res.size() << '\n';
    for (int i : res) cout << i << ' ';
}