#include <bits/stdc++.h>
using namespace std;

// nice things
typedef long long lglg;
#define len(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    lglg n; cin >> n;
    lglg p=2;
    while (p*p<=n) {
        if (n%p==0) break;
        ++p;
    }
    if (p*p>n) p = n;
    lglg x = p;
    while (x < n) x *= p;
    if (x == n) cout << p;
    else cout << 1;
}