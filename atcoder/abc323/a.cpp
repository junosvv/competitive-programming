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
    string s;
    cin >> s;
    for (int i=1; i<16; i+=2) {
        if (s[i] != '0') {
            cout << "No";
            exit(0);
        }
    }
    cout << "Yes";
}