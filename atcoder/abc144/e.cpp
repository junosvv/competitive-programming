#include <bits/stdc++.h>
using namespace std;
typedef long long lglg;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int N; lglg K; cin >> N >> K;
	lglg a[N]; for (int i=0; i<N; ++i) cin >> a[i];
	lglg f[N]; for (int i=0; i<N; ++i) cin >> f[i];

	sort(a,a+N);
	sort(f,f+N,greater<lglg>());

	lglg result = 1e13;
	for (lglg b=1e13; b>=1; b/=2) {
		while (result-b >= 0) {
			lglg req = 0;
			for (int i=0; i<N; ++i) {
				lglg val = a[i]-(result-b)/f[i];
				if (val > 0) req += val;
			}
			if (req > K) break;
			result -= b;
		}
	}
	cout << result;
}