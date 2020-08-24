#include <bits/stdc++.h>
using namespace std;
typedef long long lglg;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int N; lglg S; cin >> N >> S;
		lglg R[N];
		pair<lglg, lglg> LR[N];
		for (int i=0; i<N; ++i) {
			lglg l, r; cin >> l >> r;
			R[i] = r;
			LR[i] = {l, r};
		}
		sort(R, R+N);
		sort(LR, LR+N);
		lglg result = 0;
		for (lglg b=R[N/2]; b>=1; b/=2) {
			while (result+b <= R[N/2]) {
				lglg spent = 0; int over = 0;
				for (int i=N-1; i>=0; --i) {
					lglg l, r; tie(l, r) = LR[i];
					if (over < (N+1)/2 && result+b <= r) {
						++over;
						spent += max(l, result+b);
					} else {
						spent += l;
					}
				}
				if (spent > S) break;
				result += b;
			}
		}
		cout << result << '\n';
    }
}