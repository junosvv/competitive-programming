#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

const int MOD = 998244353;

int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1) res = res * base % MOD;
        base = base * base % MOD;
        exp /= 2;
    }
    return res;
}
#define inv(x) powa(x, MOD-2)

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    string s;
    cin >> n >> m >> s;

    int prod = 1;
    FOR(i, 1, n) if (s[i] == '?') prod = prod * i % MOD;
    cout << prod*(s[0] != '?') << ' ';

    FOR(qi, 0, m) {
        int i;
        char c;
        cin >> i >> c;
        --i;

        if (i != 0) {
            if (s[i] != '?' && c == '?') prod = prod * i % MOD;
            if (s[i] == '?' && c != '?') prod = prod * inv(i) % MOD;
        }
        s[i] = c;
        cout << prod * (s[0] != '?') << ' ';
    }
}