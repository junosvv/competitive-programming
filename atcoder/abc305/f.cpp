#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    vi par(n, -1);
    par[0] = 0;
    int u = 0;
    while (u != n-1) {
        int k;
        cin >> k;
        vi a(k);
        FOR(i, 0, k) {
            cin >> a[i];
            --a[i];
        }

        bool succ = false;
        for (int v : a) if (par[v] == -1) {
            par[v] = u;
            cout << v+1 << endl;
            u = v;
            succ = true;
            break;
        }
        if (!succ) {
            cout << par[u]+1 << endl;
            u = par[u];
        }
    }
    string s;
    cin >> s;
}