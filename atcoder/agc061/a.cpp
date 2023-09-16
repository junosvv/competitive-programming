#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto cnt2 = [&](int n) {
        int res = 0;
        int k = 2;
        while (k <= n) {
            res += n/k;
            k *= 2;
        }
        return res;
    };

    auto choose = [&](int n, int k) {
        --n;
        --k;
        if (k < 0 || k > n) return false;
        return cnt2(n) == cnt2(k) + cnt2(n-k);
    };
    
    int T;
    cin >> T;
    FOR(ti, 0, T) {
        int n, k;
        cin >> n >> k;
        
        if (!(n&1)) {
            if (choose(n/2, (k+1)/2)) {
                if (k&1) ++k;
                else --k;
            }
        } else {
            if (choose(n/2, k/2)) {
                if (k&1) --k;
                else ++k;
            }
            if (choose(n/2, (k+1)/2)) {
                if (k&1) ++k;
                else --k;
            }
        }
        cout << k << '\n';
    }
}