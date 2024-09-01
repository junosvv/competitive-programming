#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define t3i tuple<int,int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, q;
    cin >> n >> q;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];

    auto check = [&](vi& b) {
        int n = b.size();
        // cout << "proc ";
        // for (int i : b) cout << i << ' ';
        // cout << '\n';

        FOR(i, 0, n-5) {
            if (b[i] < b[i+1] + b[i+2]) {
                FOR(l, i+3, n-2) {
                    if (b[l] < b[l+1] + b[l+2]) {
                        // cout << i << ' ' << l << " works1\n";
                        return true;
                    }
                }
            }
            int l = i+1;
            FOR(j, i+2, i+6) {
                FOR(k, j+1, i+6) {
                    if (b[i] >= b[j] + b[k]) continue;
                    FOR(m, l+1, i+6) if (m != j && m != k) {
                        FOR(p, m+1, i+6) if (p != j && p != k) {
                            if (b[l] < b[m] + b[p]) {
                                // cout << i << ' ' << j << ' ' << k << " works2\n";
                                return true;
                            }
                        }
                    }
                }
            }
            int j = i+1;
            l = i+2;
            FOR(k, l+1, i+6) {
                if (b[i] >= b[j] + b[k]) continue;
                FOR(m, l+1, i+6) if (m != k) {
                    FOR(p, m+1, i+6) if (p != k) {
                        if (b[l] < b[m] + b[p]) {
                            // cout << i << ' ' << j << ' ' << k << " works3\n";
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    };

    vi res(q);
    FOR(qi, 0, q) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        if (r-l+1 > 50) res[qi] = 1;
        else {
            vi b(r-l+1);
            FOR(i, l, r+1) b[i-l] = a[i];
            sort(b.begin(), b.end(), greater<int>());
            res[qi] = check(b);
        }
    }
    for (int i : res) cout << (i ? "YES" : "NO") << '\n';
}