#include <bits/stdc++.h>
using namespace std;

typedef long long lglg;

int main() {
    ios::sync_with_stdio(0);//, cin.tie(0), cout.tie(0);

	int N,K,Q; cin >> N >> K >> Q;
	int correct[N+1] = {};

	for (int i=0; i<Q; ++i) {
		int a; cin >> a;
		++correct[a];
	}
	for (int i=1; i<=N; ++i) {
		if (correct[i] > Q-K) cout << "Yes\n";
		else cout << "No\n";
	}
}