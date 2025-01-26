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

    const int MOD = 998244353;
    
    auto solve = [&]() {
        int n, m;
        cin >> n >> m;
        vi a(n), b(m);
        multiset<int> aa, bb;
        FOR(i, 0, n) {
            cin >> a[i];
            aa.insert(a[i]);
        }
        FOR(i, 0, m) {
            cin >> b[i];
            bb.insert(b[i]);
        }
        
        while (!aa.empty() && !bb.empty()) {
            int x = *bb.begin();
            bb.erase(bb.begin());
            if (x < *aa.begin()     ) {
                cout << "No\n";
                return;
            }
            if (aa.count(x)) {
                aa.erase(aa.find(x));
                continue;
            }
            bb.insert(x/2);
            bb.insert((x+1)/2);
        }
        if (aa.empty() && bb.empty()) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}