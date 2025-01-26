#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>
#define pii pair<int,int>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define mii map<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    auto solve = [&]() {
        int n;
        cin >> n;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        sort(a.begin(), a.end());
        
        multiset<int> diffs;
        FOR(i, 1, n) {
            diffs.insert(a[i] - a[i-1]);
        }

        FOR(i, 1, n) {
            if (a[i] == a[i-1]) {
                if (i-2 >= 0) diffs.erase(diffs.find(a[i-1]-a[i-2]));
                diffs.erase(diffs.find(0));
                if (i+1 < n) diffs.erase(diffs.find(a[i+1]-a[i]));
                if (i-2 >= 0 && i+1 < n) diffs.insert(a[i+1]-a[i-2]);

                int best = *diffs.begin();
                if (best < 2*a[i]) {
                    cout << a[i] << ' ' << a[i] << ' ';
                    vi nw;
                    FOR(j, 0, n) if (j != i-1 && j != i) {
                        nw.push_back(a[j]);
                    }
                    FOR(j, 1, nw.size()) {
                        if (nw[j] - nw[j-1] == best) {
                            cout << nw[j-1] << ' ' << nw[j] << '\n';
                            return;
                        }
                    }
                    assert(false);
                }

                if (i-2 >= 0) diffs.insert(a[i-1]-a[i-2]);
                diffs.insert(0);
                if (i+1 < n) diffs.insert(a[i+1]-a[i]);
                if (i-2 >= 0 && i+1 < n) diffs.erase(diffs.find(a[i+1]-a[i-2]));
            }
        }
        cout << "-1\n";
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}