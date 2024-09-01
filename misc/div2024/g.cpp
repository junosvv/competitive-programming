#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    vector<string> words(9);
    FOR(i, 0, 9) cin >> words[i];

    int m;
    cin >> m;
    vvi R(9, vi(9));
    FOR(i, 0, m) {
        string s, t;
        cin >> s >> t;
        FOR(j, 0, 9) if (words[j] == s) {
            FOR(k, 0, 9) if (words[k] == t) {
                R[j][k] = 1;
                R[k][j] = 1;
            }
        }
    }

    vi perm(9);
    FOR(i, 0, 9) perm[i] = i;
    do {
        bool fail = false;
        FOR(i, 0, 3) {
            FOR(j, 0, 3) {
                if (!R[perm[3*i+j]][perm[3*i+(j+1)%3]]) {
                    fail = true;
                    break;
                }
            }
            if (fail) break;
        }
        if (!fail) {
            cout << "Possible\n";
            FOR(i, 0, 3) {
                FOR(j, 0, 3) cout << words[perm[3*i+j]] << ' ';
                cout << '\n';
            }
            exit(0);
        }
    } while (next_permutation(perm.begin(), perm.end()));

    cout << "Impossible";
}