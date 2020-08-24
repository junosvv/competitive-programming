#include <bits/stdc++.h>
using namespace std;

// nice things
typedef long long lglg;
#define len(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        string s, t; cin >> s >> t;
        int a = -1, b = -1;
        bool fail = false;
        for (int i=0; i<N; ++i) {
            if (s[i] != t[i]) {
                if (a == -1) a = i;
                else if (b == -1) b = i;
                else {
                    fail = true;
                    break;
                }
            }
        }
        if (a != -1 && b == -1) fail = true;
        else if (a != -1 && b != -1 && s[a] != s[b] || t[a] != t[b]) fail = true;
        if (fail) cout << "No\n";
        else cout << "Yes\n";
    }
}