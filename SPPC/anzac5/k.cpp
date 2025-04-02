#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define lg long long

string canon(string& s) {
    string t;
    char x = 'a';
    map<char, char> trans;
    for (char c : s) {
        if (!trans.count(c)) {
            trans[c] = x++;
        }
        t += trans[c];
    }
    return t;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    map<string, vector<string>> forms;
    FOR(i, 0, n) {
        string s;
        cin >> s;
        string cs = canon(s);
        forms[cs].push_back(s);
    }
    
    int q;
    cin >> q;
    FOR(qi, 0, q) {
        string s;
        while (true) {
            getline(cin, s);
            if (s != "") break;
        }
        vector<string> words(1);
        FOR(i, 0, s.size()) {
            if (s[i] == ' ') words.push_back({});
            else words.back() += s[i];
        }
        bool impos = false;
        vi canbe(26, (1<<26) - 1);
        for (string& s : words) {
            string cs = canon(s);
            if (!forms.count(cs)) {
                impos = true;
                break;
            }
            int ths = (1 << 26) - 1;
            for (string& poss : forms[cs]) {
                FOR(i, 0, s.size()) {
                    
                }
            }
        }
    }
}