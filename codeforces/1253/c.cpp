#include <bits/stdc++.h>
using namespace std;

typedef long long lglg;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m; cin >> n >> m;
    int a[n]; for (int i=0; i<n; ++i) cin >> a[i];
    sort(a, a+n);

    lglg parities[n] = {};

    lglg sums[m] = {};
    for (int i=0; i<n; ++i) {
        sums[i%m] += a[i];
        parities[i] += sums[i%m]; 
    }

    lglg sum = 0;
    for (int k=0; k<n; ++k) {
        sum += parities[k];
        cout << sum << " ";
    }
}