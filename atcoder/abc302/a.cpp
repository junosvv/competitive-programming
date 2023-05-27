#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++(i))
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int a, b;
    cin >> a >> b;
    
    cout << (a+b-1) / b;
}