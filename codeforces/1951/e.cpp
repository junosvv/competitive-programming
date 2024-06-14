#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    auto is_palindrome = [&](string& s) {
        int n = s.size();
        FOR(i, 0, n/2) if (s[i] != s[n-1-i]) return false;
        return true;
    };

    auto solve = [&]() {
        string s;
        cin >> s;
        int n = s.size();

        if (!is_palindrome(s)) {
            cout << "YES\n1\n" << s << '\n';
            return;
        }

        bool aabaa = true;
        FOR(i, 1, n/2) if (s[i] != s[i-1]) {
            aabaa = false;
            break;
        }
        bool ababa = true;
        FOR(i, 1, n) if (s[i] != s[i&1]) {
            ababa = false;
            break;
        }
        if (aabaa || ababa) {
            cout << "NO\n";
            return;
        }
        
        cout << "YES\n2\n";
        if (s[0] != s[1]) {
            cout << s[0] << s[1] << ' ' << s.substr(2, n-2) << '\n';
            return;
        }

        FOR(i, 2, n) if (s[i] != s[0]) {
            string t = s.substr(i+1, n-i-1);
            if (!is_palindrome(t)) {
                cout << s.substr(0, i+1) << ' ' << t << '\n';
                return;
            }
            cout << s.substr(0, i+2) << ' ' << s.substr(i+2, n-i-2) << '\n';
            return;
        };
    };

    int T;
    cin >> T;
    FOR(t, 0, T) solve();
}