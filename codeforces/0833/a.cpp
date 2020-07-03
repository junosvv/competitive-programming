#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
ll MOD = 1000000007;
ll INF = 1LL << 60;
ll HI = 1000005;
 
ll cubic_root(ll x) { // cube root round down i.e. highest true
    ll lo = 0, hi = HI;
    while (lo < hi) {
        ll m = lo + ((hi - lo + 1) / 2);
        if (m * m * m > x)
            hi = m - 1;
        else
            lo = m;
    }
    return lo;
}
 
ll a, b, ab, cuberoot;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
 
    int n;
    cin >> n;
 
    while (n--) {
        cin >> a >> b;
        ab = a * b;
        cuberoot = cubic_root(ab);
 
        if (cuberoot * cuberoot * cuberoot != ab) {
            cout << "No\n";
            continue;
        }
 
        if (a % cuberoot == 0 && b % cuberoot == 0) {
            cout << "Yes\n";
            continue;
        }
 
        cout << "No\n";
    }
}