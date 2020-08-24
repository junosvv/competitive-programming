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
    
    lglg MOD = 1000000007;
    string str; cin >> str;
    str += 'a';
    int countU = 0, countN = 0;
    int big = 100123;
    lglg fibs[big] = {0, 1};
    for (int i=2; i<big; ++i) {
        fibs[i] = (fibs[i-1] + fibs[i-2]) % MOD;
    }
    
    lglg result = 1;
    for (char c : str) {
        if (c == 'm' || c == 'w') {
            result = 0;
            break;
        }
        if (c == 'u') {
            ++countU;
            if (countN > 0) {
                result *= fibs[countN+1];
                result %= MOD;
                countN = 0;
            }
        } else if (c == 'n') {
            ++countN;
            if (countU > 0) {
                result *= fibs[countU+1];
                result %= MOD;
                countU = 0;
            }
        } else {
            if (countN > 0) {
                result *= fibs[countN+1];
                result %= MOD;
                countN = 0;
            } else if (countU > 0) {
                result *= fibs[countU+1];
                result %= MOD;
                countU = 0;
            }
        }
    }
    cout << result;
}