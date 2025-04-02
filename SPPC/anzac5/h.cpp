#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define lg long long

string canon(string& s) {
    string t;
    char x = 'a';
    map<char, char> trans;
    for (char c : s) {
        if (!trans.count(c)) {
            trans[c] = x++;
        }
        t += trans[c];
    }
    return t;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int T;
    cin >> T;

    const int BIG = 20005;
    vi sigma(BIG);
    FOR(x, 1, BIG) {
        for (int d=1; d*d<=x; ++d) {
            if (x%d == 0) {
                sigma[x] += d;
                if (d*d!=x) sigma[x] += x/d;
            }
        }
        sigma[x] -= x;
    }

    while (T--) {
        int lo, hi;
        cin >> lo >> hi;
        cout << "Amicable numbers between " << lo << " and " << hi << '\n';
        bool seen = false;
        FOR(x, lo, hi+1) {
            if (sigma[x] > x && sigma[x] <= hi && sigma[sigma[x]] == x) {
                seen = true;
                cout << x << ' ' << sigma[x] << '\n';
            }
        }
        if (!seen) cout << "None" << '\n';
    }
}