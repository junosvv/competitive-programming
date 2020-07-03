#include <bits/stdc++.h>
using namespace std;
typedef long long lglg;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	lglg a, b; cin >> a >> b;
	lglg gcd = __gcd(a, b);

	lglg result = 1;
	for (lglg i=2; i*i<=gcd; ++i) {
		lglg done = 0;
		while (gcd%i == 0) {
			done = 1;
			gcd /= i;
		}
		result += done;
	}
	if (gcd > 1) ++result;
	cout << result;
}