#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    int res = 0;
    while (n) {
        if (n%3 == 0) n /= 3;
        else --n;
        ++res;
    }

    cout << res;
}