#include <bits/stdc++.h>
using namespace std;

// nice things
typedef long long lglg;
#define len(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

void flip(string &s, string &t, vector<int> &a, vector<int> &b, int &moves, int i, int j) {
    swap(s[i], t[j]);
    a.push_back(i+1);
    b.push_back(j+1);
    ++moves;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s, t; cin >> s >> t;
        string ssort = s, tsort = t;
        sort(ssort.begin(), ssort.end());
        sort(tsort.begin(), tsort.end());
        if (ssort != tsort) {
            cout << "NO\n";
            continue;
        }
        bool dup = false;
        for (int i=1; i<n; ++i) {
            if (ssort[i-1] == ssort[i]) {
                dup = true;
                break;
            }
        }
        if (!dup) {
            for (int i=1; i<n; ++i) {
                if (tsort[i-1] == tsort[i]) {
                    dup = true;
                    break;
                }
            }
        }
        if (dup) {
            cout << "YES\n";
            continue;
        }
        lglg inv = 0;
        for (int i=0; i<n; ++i) {
            for (int j=i+1; j<n; ++j) {
                if (t[j] < t[i]) ++inv;
                if (s[j] < s[i]) ++inv;
            }
        }
        if (inv%2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}