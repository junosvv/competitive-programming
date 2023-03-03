#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

int solve(vi a) {
    int n = a.size();
    // cout << "here: ";
    // FOR(i, 0, n) cout << a[i] << ' ';
    // cout << '\n';
    int csum = 0;
    multiset<int> st;
    int res = 0;
    FOR(i, 0, n) {
        if (a[i] < 0) st.insert(a[i]);
        csum += a[i];
        if (csum < 0) {
            ++res;
            int x = *st.begin();
            st.erase(st.begin());
            csum -= x*2;
        }
    }
    return res;
}
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        --m;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        vi b;
        FOR(i, m+1, n) b.push_back(a[i]);
        int res = solve(b);
        b.clear();
        ROF(i, m, 0) b.push_back(-a[i]);
        res += solve(b);
        cout << res << '\n';
    }
}