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
    
    int n, m;
    cin >> n >> m;
    priority_queue<int,vi,greater<int>> times;
    map<int,vector<pii>> mp;
    set<int> row;
    FOR(i, 0, n) row.insert(i);
    FOR(i, 0, m) {
        int t, w, s;
        cin >> t >> w >> s;
        times.push(t);
        mp[t].emplace_back(w, s);
    }
    vi res(n);
    int last_t = -1;
    while (!times.empty()) {
        int t = times.top();
        times.pop();
        if (t == last_t) continue;
        last_t = t;
        int last_w = -1, last_s;
        for (pii pr : mp[t]) {
            int w = pr.first, s = pr.second;
            if (w == 0) row.insert(s);
            else {
                last_w = w;
                last_s = s;
            }
        }
        if (last_w != -1 && !row.empty()) {
            int u = *row.begin();
            row.erase(row.begin());
            res[u] += last_w;
            int tt = t + last_s;
            times.push(tt);
            mp[tt].emplace_back(0, u);
            // cout << u+1 << " gets " << last_w << '\n';
        }
    }
    for (int i : res) cout << i << '\n';
}