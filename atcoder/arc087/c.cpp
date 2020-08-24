#include <bits/stdc++.h>
using namespace std;
 
signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
 
    map<int, int> occ;
    for (int i=0; i<n; ++i) ++occ[a[i]];
 
    int res = 0;
    for (auto pr : occ) {
        int x = pr.first;
        if (occ[x] < x) res += occ[x];
        else res += occ[x] - x;
    }
    cout << res;
}