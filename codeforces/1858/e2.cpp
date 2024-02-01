#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int q;
    cin >> q;
    vi a, dist, mem, memdist;
    const int BIG = 1e6+1;
    vector<set<int>> locs(BIG);
    int n = 0;

    FOR(qi, 0, q) {
        char c;
        cin >> c;
        if (c == '?') {
            if (n == 0) cout << 0 << endl;
            else cout << dist[n-1] << endl;
        } else if (c == '+') {
            int x;
            cin >> x;
            if (n >= a.size()) {
                a.push_back(0);
                dist.push_back(0);
            }

            locs[a[n]].erase(n);
            locs[x].insert(n);

            memdist.push_back(dist[n]);
            dist[n] = (n == 0 ? 0 : dist[n-1]);
            if (*locs[x].begin() >= n) ++dist[n];

            mem.push_back(a[n]);
            a[n++] = x;
        } else if (c == '-') {
            int x;
            cin >> x;
            n -= x;
            mem.push_back(-x);
        } else {
            int x = mem.back();
            mem.pop_back();
            if (x < 0) {
                n -= x;
            } else {
                --n;

                dist[n] = memdist.back();
                memdist.pop_back();
                
                locs[a[n]].erase(n);
                locs[x].insert(n);

                a[n] = x;
            }
        }
    }
}