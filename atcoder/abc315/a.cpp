#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string s;
    cin >> s;
    for (char c : s) if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') cout << c;
}