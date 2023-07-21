#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    string s;
    cin >> n >> s;

    int res = 0, over = 0, size = 0;
    ROF(i, n-1, -1) {
        if (s[i] == '1') ++size;
        res += over + (size+1)/2;
        if (s[i] == '0') {
            over += size/2 + 1;
            size = 0;
        }
    } 
    cout << res;
}