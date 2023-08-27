#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vpii vector<pii>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, K;
    cin >> n >> K;
    vi a(n);
    FOR(i, 0, n) cin >> a[i];
    // sort(a.begin(), a.end());

    vpii aida = {{0, 0}};
    FOR(i, 0, n) {
        vpii aida2 = aida, aida3;
        for (pii& pr : aida2) {
            pr.first += a[i];
            pr.second += a[i];
        }

        // cout << "1: ";
        // for (pii pr : aida) cout << pr.first << "," << pr.second << "  ";
        // cout << '\n';
        // cout << "2: ";
        // for (pii pr : aida2) cout << pr.first << "," << pr.second << "  ";
        // cout << '\n';

        int j=0, k=0;
        while (j < aida.size() && k < aida2.size()) {
            if (max(aida[j].first, aida2[k].first) <= 1 + min(aida[j].second, aida2[k].second)) {
                aida3.emplace_back(min(aida[j].first, aida2[k].first), max(aida[j].second, aida2[k].second));
                ++j;
                ++k;
            } else if (aida[j].first < aida2[k].first) aida3.push_back(aida[j++]);
            else aida3.push_back(aida2[k++]);
        }
        while (j < aida.size()) aida3.push_back(aida[j++]);
        while (k < aida2.size()) aida3.push_back(aida2[k++]);
        if (aida3.size() > K+1) aida3.resize(K+1);

        aida = aida3;

        cout << "3: ";
        for (pii pr : aida) cout << pr.first << "," << pr.second << "  ";
        cout << '\n';
    }

    int r = 1;
    vi res;
    for (pii pr : aida) {
        FOR(i, r, pr.first) {
            res.push_back(i);
            if (res.size() == K) break;
        }
        if (res.size() == K) break;
        r = max(r, pr.second + 1);
    }
    while (res.size() < K) res.push_back(r++);
    for (int i : res) cout << i << ' ';
}