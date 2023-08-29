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

    vector<string> strs = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};

    for (string t : strs) if (t == s) {
        cout << "Yes";
        exit(0);
    }
    cout << "No";
}