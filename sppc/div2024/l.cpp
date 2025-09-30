#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> strings(n);
    FOR(i, 0, n) cin >> strings[i];

    vi cnt(26);
    vvi ccnt(26, vi(27));
    FOR(i, 0, n) {
        int m = strings[i].size();
        FOR(j, 1, m) {
            ++cnt[strings[i][j-1]-'a'];
            ++ccnt[strings[i][j-1]-'a'][strings[i][j]-'a'];
        }
        ++cnt[strings[i][m-1]-'a'];
        ++ccnt[strings[i][m-1]-'a'][26];
    }

    FOR(i, 0, 26) {
        if (cnt[i] == 0) {
            cnt[i] = 1;
            ccnt[i][26] = 1;
        }
    }

    int m = s.size();
    long double res = 1;
    FOR(i, 1, m) {
        res *= (long double)ccnt[s[i-1]-'a'][s[i]-'a'] / cnt[s[i-1]-'a'];
    }
    res *= (long double)ccnt[s[m-1]-'a'][26] / cnt[s[m-1]-'a'];

    cout << setprecision(20) << res;
}