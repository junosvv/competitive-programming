#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>
 
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vi marked(n);
    FOR(i, 0, m) {
        int u, v;
        cin >> u >> v;
        marked[v-1] = 1;
    }
    if (accumulate(marked.begin(), marked.end(), 0LL) == n-1) {
        FOR(i, 0, n) if (!marked[i]) {
            cout << i+1;
            exit(0);
        }
    }
    cout << -1;
}