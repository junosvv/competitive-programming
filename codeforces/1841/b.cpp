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
        vi a;
        int inv = 0;
        vi res(n);
        FOR(i, 0, n) {
            a.push_back(0);
            cin >> a.back();
            int newinv = inv;
            int m = a.size();
            if (m >= 2 && a[m-2] > a[m-1]) ++newinv;
            if (newinv == 0 || newinv == 1 && a[m-1] <= a[0]) {
                inv = newinv;
                res[i] = 1;
            } else {
                a.pop_back();
            }
        }
        FOR(i, 0, n) cout << res[i];
        cout << '\n';
    }
}