#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 998244353;
#define inv(x) powa(x, MOD-2)

int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1LL) res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}

signed main() {
    int n, m;
    cin >> n >> m;
    vi a(m);
    FOR(i, 0, m) cin >> a[i];
    vi scores(n);
    vvi tosolve(n);
    FOR(i, 0, n) {
        scores[i] = i+1;
        string s;
        cin >> s;
        FOR(c, 0, m) {
            if (s[c] == 'o') scores[i] += a[c];
            else tosolve[i].push_back(a[c]);
        }
        sort(tosolve[i].begin(), tosolve[i].end());
    }
    int mx = *max_element(scores.begin(), scores.end());
    FOR(i, 0, n) {
        int cnt = 0;
        while (scores[i] < mx) {
            scores[i] += tosolve[i].back();
            tosolve[i].pop_back();
            ++cnt;
        }
        cout << cnt << ' ';
    }
}