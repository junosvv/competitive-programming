#include <bits/stdc++.h>
using namespace std;

// nice things
typedef long long lglg;
#define len(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))
#define help(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); _help(_it, args); }
void _help(istream_iterator<string> it) {}
template<typename T, typename... Args>
void _help(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " is " << a << "\n";
	_help(++it, args...);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        int my[3], yo[3] = {};
        for (int i=0; i<3; ++i) cin >> my[i];
        string str; cin >> str;
        char result[n] = {};
        int wins = 0;
        for (int i=0; i<n; ++i) {
            int move;
            if (str[i] == 'R') move = 1;
            else if (str[i] == 'P') move = 2;
            else move = 0;
            
            if (my[move] > 0) {
                --my[move];
                result[i] = "RPS"[move];
                ++wins;
            }
        }
        if (wins < ceil((double)n/2)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i=0; i<n; ++i) {
                if (result[i] == 'R' || result[i] == 'P' || result[i] == 'S') cout << result[i];
                else {
                    for (int move=0; move<3; ++move) {
                        if (my[move] > 0) {
                            cout << "RPS"[move];
                            --my[move];
                            break;
                        }
                    }
                }
            }
            cout << '\n';
        }
    }
}