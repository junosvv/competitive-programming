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
        int A, B, C, k;
        cin >> A >> B >> C >> k;
        int M = max(A, B);
        int cnt = 0;
        bool succ = false;
        FOR(a, pow(10, A-1), pow(10, A)) {
            int l = max(pow(10, B-1), pow(10, C-1)-a);
            int u = min(pow(10, B)-1, pow(10, C)-1-a);

            if (l <= u) {
                int nw = u - l + 1;
                if (k <= cnt + nw) {
                    int b = k-cnt-1+l;
                    cout << a << " + " << b << " = " << a+b << '\n';
                    succ = true;
                    break;
                }
                cnt += nw;
            }
        }
        if (!succ) cout << -1 << '\n';
    }
}
