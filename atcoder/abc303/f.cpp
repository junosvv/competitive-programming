#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>
#define t3i tuple<int,int,int>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
 
    int n, h;
    cin >> n >> h;
    vector<t3i> spells(n);
    FOR(i, 0, n) {
        int t, d;
        cin >> t >> d;
        spells[i] = {t*d, t, d};
    }
    spells.emplace_back(0, 0, 1e10);
    ++n;
    vector<t3i> spells0 = spells;
 
    auto check = [&](int k) {
        spells = spells0;
        FOR(i, 0, n) {
            int _, t, d;
            tie(_, t, d) = spells[i];
            t = min(t, k);
            spells[i] = {t*d, t, d};
        }
        sort(spells.begin(), spells.end(), greater<t3i>());
        vector<t3i> spells00 = spells;
        spells = {spells00[0]};
        FOR(i, 1, n) {
            int _, t, d;
            tie(_, t, d) = spells00[i];
            if (d > get<2>(spells.back())) {
                spells.push_back(spells00[i]);
            }
        }
        int res = 0;
        FOR(i, 0, spells.size()) {
            assert(i != (int)spells.size()-1);
            int p, t, d;
            tie(p, t, d) = spells[i];
            t = min(t, k);
            p = t*d;
 
            int nextp = get<0>(spells[i+1]);
 
            if (k > t) {
                if (k-t >= (h-res+p-1)/p) return true;
                res += p*(k-t);
                k = t;
            }
 
            int c = min(k, (p - nextp) / d + 1);
            int cur = 2*p - (c-1)*d;
            if (cur >= (2*(h - res) + (c-1)) / c) return true;
            res += cur * c / 2;
            k -= c;
            if (k <= 0) return false;
        }
        return false;
    };
 
    int k = h;
    for (int b=h; b>=1; b/=2) {
        while (k-b>=1 && check(k-b)) k -= b;
    }
    cout << k;
}