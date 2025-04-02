// n.cpp
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

    string t;
    int i = 0;
    while (i < n) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            t += s[i];
            ++i;
        } else {
            string mynum;
            while ('0' <= s[i] && s[i] <= '9') {
                mynum += s[i];
                ++i;
            }
            --i;
            int times = stoi(mynum);
            if (s[i+1] == '(') {
                int j = i+2;
                string w;
                while (s[j] != ')') {
                    w += s[j];
                    ++j;
                }
                FOR(k, 0, times) t += w;
                i = j + 1;
            } else {
                FOR(k, 0, times) t += s[i+1];
                i += 2;
            }
        }
    }
    cout << t << '\n';

    vi res(4);
    for (char c : t) {
        if (c == 'S') ++res[0];
        if (c == 'T') ++res[1];
        if (c == 'R') ++res[2];
        if (c == 'L') ++res[3];
    }
    for (int i : res) cout << i << ' ';
    cout << '\n';
}
