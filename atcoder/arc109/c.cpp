#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define int long long
#define vi vector<int>

template <class T> ostream& operator<<(ostream& os, vector<T>& x) {
    os << '[';
    bool first = true;
    for (T& i : x) {
        if (!first) os << ", ";
        first = false;
        os << i;
    }
    return os << ']';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    auto f = [](char a, char b) {
        if (a == b || a == 'R' && b == 'S' || a == 'S' && b == 'P' || a == 'P' && b == 'R') return a;
        return b;
    };

    FOR(ki, 0, k) {
        string t = s;
        if (s.size()&1) {
            t += s;
        }
        s = "";
        for (int i=0; i<t.size(); i+=2) {
            s.push_back(f(t[i], t[i+1]));
        }
    }
    cout << s[0] << '\n';
}
