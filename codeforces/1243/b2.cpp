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
        int count[26] = {};
        for (int i=0; i<n; ++i) {
            ++count[s[i]-'a'];
            ++count[t[i]-'a'];
        }
        bool no = false;
        for (int i=0; i<26; ++i) {
            if (count[i]%2 == 1) {
                cout << "No\n";
                no = true;
                break;
            }
        }
        if (!no) {
            cout << "Yes\n";
            int moves = 0;
            vector<int> outA, outB;
            for (int pos=0; pos<n; ++pos) {
                if (s[pos] == t[pos]) continue;
                int x=pos+1; while (x<n && s[x] != s[pos]) ++x;
                if (x<n) flip(s, t, outA, outB, moves, x, pos);
                else {
                    int x=pos+1; while (x<n && t[x] != s[pos]) ++x;
                    if (x==n) assert(false);
                    else {
                        flip(s, t, outA, outB, moves, pos+1, x);
                        flip(s, t, outA, outB, moves, pos+1, pos);
                    }
                }
            }
            cout << moves << '\n';
            for (int i=0; i<moves; ++i) cout << outA[i] << " " << outB[i] << '\n';
        }
    }
}