#include <bits/stdc++.h>
using namespace std;
typedef long long lglg;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int T; cin >> T;
    while (T--) {
        int M; cin >> M;
		lglg maxmons = -1, mons[M]; for (int i=0; i<M; ++i) {
			cin >> mons[i];
			maxmons = max(maxmons, mons[i]);
		}
		int H; cin >> H;
		lglg maxpower = -1;
		pair<int, lglg> heroes[H+1];
		for (int i=0; i<H; ++i) {
			lglg p; int e; cin >> p >> e;
			heroes[i] = {e, p};
			maxpower = max(maxpower, p);
		}
		if (maxmons > maxpower) {
			cout << "-1\n";
			continue;
		}
		heroes[H] = {0, -1};
		sort(heroes, heroes+(H+1));
		int h = H, e = M;
		lglg mx = -1, finder[M+1];
		while (h>=0) {
			if (e > heroes[h].first) {
				finder[e--] = mx;
				continue;
			}
			mx = max(mx, heroes[h--].second);
			finder[e] = mx;
		}
		int defeated = 0, result = 0;
		while (defeated < M) {
			int ln = 1;
			lglg mx = mons[defeated];
			while (defeated+ln < M) {
				mx = max(mx, mons[defeated+ln]);
				if (mx > finder[ln+1]) break;
				++ln;
			}
			defeated += ln;
			++result;
		}
		cout << result << '\n';
    }
}