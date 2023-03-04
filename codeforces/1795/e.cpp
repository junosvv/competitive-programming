#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];

        vector<vi> res(2, vi(n));
        FOR(cyc, 0, 2) {
            vector<pii> st;
            FOR(i, 0, n) {
                if (i >= 1) res[cyc][i] += res[cyc][i-1];
                if (cyc) st.emplace_back(a.rbegin()[i], a.rbegin()[i]);
                else st.emplace_back(a[i], a[i]);

                while (st.size() >= 2) {
                    int a, b, c, d;
                    tie(a, b) = st.rbegin()[0];
                    tie(c, d) = st.rbegin()[1];
                    if (b > c + 1) break;
                    res[cyc][i] += (c-d+1) * (c-b+1);
                    d = b - (c-d+1);
                    if (d <= 0) {
                        res[cyc][i] -= (-d)*(-d+1)/2;
                        d = 1;
                    }
                    c = a;
                    st.pop_back();
                    st.back() = {c, d};
                }
            }
        }
        
        reverse(res[1].begin(), res[1].end());
        FOR(i, 0, n) a[i] += res[0][i] + res[1][i];
        cout << *min_element(a.begin(), a.end()) << '\n';
    }
}