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

    cout << setprecision(10);
    
    int tele[100] = {};
    for (int r=9; r>=0; --r) {
        int c = (r%2==0) ? 0 : 9;
        while (true) {
            if ((r%2==0 && c == 10) || (r%2==1 && c == -1)) break;
            int a; cin >> a;
            tele[10*r+c] = 10*(r+a)+(a%2==0?c:9-c);
            if (r%2==0) ++c;
            else --c;
        }
    }

    double dp[100]; dp[99] = 0;
    for (int i=98; i>=0; --i) {
        int moves = 0;
        double result = 6;
        for (int r=1; r<=6; ++r) {
            if (i+r <= 99) {
                result += min(dp[i+r], dp[tele[i+r]]);
                ++moves;
            }
        }
        dp[i] = result / moves;
    }

    cout << dp[0];
}