#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    cin >> T;
    FOR(t, 0, T) {
        int n;
        cin >> n;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        vi b;
        FOR(i, 0, n) if (a[i] == 2) {
            FOR(j, i, n+i+1) {
                int y = a[j%n];
                if (!b.empty()) {
                    int x = b.back();
                    if (x == y || x == 2 && y == 1 || x == 3 && y == 4) continue;
                    if (x == 1 && y == 2 || x == 4 && y == 3) b.pop_back();
                }
                b.push_back(y);
            }
            b.pop_back();
            break;
        }
        vi cnt(5);
        for (int i : b) ++cnt[i];
        cout << (cnt[1] < cnt[3] && cnt[4] < cnt[2] ? "Yes" : "No") << '\n';
    }
}