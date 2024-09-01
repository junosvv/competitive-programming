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
    int n = s.size();

    auto is_palindrome = [&](string& s) {
        int n = s.size();
        FOR(i, 0, n/2) if (s[i] != s[n-1-i]) return false;
        return true;
    };

    FOR(i, 0, n) {
        string t = s.substr(0, i);
        reverse(t.begin(), t.end());
        t = s + t;
        if (is_palindrome(t)) {
            cout << i;
            exit(0);
        }
    }
}