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
    cin >> n;
    set<string> st;
    FOR(i, 0, n) {
        string s;
        cin >> s;
        string t = s;
        reverse(t.begin(), t.end());
        if (t < s) s = t;
        st.insert(s);
    }
    cout << st.size();
}