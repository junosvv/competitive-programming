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
		int a[n]; for (int i=0; i<n; ++i) cin >> a[i];
		int left[n+1]; for (int i=0; i<n+1; ++i) left[i] = -1;
		int best = -1;
		for (int i=0; i<n; ++i) {
			if (left[a[i]] != -1) {
				int val = i - left[a[i]] + 1;
				if (best == -1 || val < best) best = val;
			}
			left[a[i]] = i;
		}
		cout << best << '\n';
	}
}