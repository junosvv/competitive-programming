#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    int p2 = 1;
    FOR(i, 0, 60) {
        int p3 = 1;
        FOR(j, 0, 60) {
            if (p2*p3 > n) break;
            if (p2*p3 == n) {
                cout << "Yes";
                exit(0);
            }
            p3 *= 3;
        }
        p2 *= 2;
    }
    cout << "No";
}