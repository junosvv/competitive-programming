#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int T;
    cin >> T;
    FOR(t, 0, T) {
        int n;
        cin >> n;

        vi cnt(100);
        FOR(i, 0, n) {
            int x;
            cin >> x;
            ++cnt[x];
        }
        bool res = true;
        FOR(i, 1, 100) {
            if (cnt[i] > cnt[i-1]) res = false;
        }
        cout << (res ? "YES" : "NO") << '\n';
    }
}