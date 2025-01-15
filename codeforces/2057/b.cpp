#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>
#define mii map<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    auto solve = [&]() {
        int n, k;
        cin >> n >> k;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];

        mii freq;
        priority_queue<pii> pq;
        for (int x : a) {
            ++freq[x];
            pq.emplace(-freq[x], x);
        }

        FOR(i, 0, k) {
            while (!pq.empty()) {
                int fx = -pq.top().first, x = pq.top().second;
                pq.pop();
                if (freq[x] != fx) continue;
                --freq[x];
                if (freq[x]) pq.emplace(-freq[x], x);
                break;
            }
        }
        int res = 0;
        for (pii pr : freq) if (pr.second) ++res;
        cout << max(1LL, res) << '\n';
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}