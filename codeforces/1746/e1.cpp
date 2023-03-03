#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;

    auto lg = [&](int x) {
        int res = 0;
        while (x >= 2) {
            ++res;
            x >>= 1;
        }
        return res;
    };
    int k = 1 + lg(n);

    vector<vi> queries(k);
    FOR(j, 0, k) {
        FOR(x, 1, n+1) if ((x>>j)&1) queries[j].push_back(x);
    }
    auto query = [&](int j) {
        cout << "? " << queries[j].size() << ' ';
        for (int i : queries[j]) cout << i << ' ';
        cout << endl;
        string s;
        cin >> s;
        return s == "YES";
    };

    int base = 0;
    vector<vi> res(2, vi(k));
    res[1][0] = 1;
    int a = -1;
    FOR(j, 1, k) {
        if (a == -1) a = query(base);
        int b = query(j);
        int c = query(j);
        if (b == c) {
            res[0][j] = b;
            res[1][j] = b;
            a = -1;
        } else {
            int d = query(base);
            if (a == d) {
                FOR(i, base, j) res[!d][i] = res[d][i];
                base = j;
                res[1][base] = 1;
                a = -1;
            } else {
                res[a][j] = c;
                res[!a][j] = !c;
                a = d;
            }
        }
    }
    
    FOR(d, 0, 2) {
        int ans = 0;
        FOR(j, 0, k) if (res[d][j]) ans += 1<<j;
        if (!ans) continue;
        cout << "! " << ans << endl;
        string s;
        cin >> s;
        if (s == ":)") break;
    }
}