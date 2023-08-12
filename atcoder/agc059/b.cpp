#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int T;
    cin >> T;
    FOR(t, 0, T) {
        int n;
        cin >> n;
        vi a(n), cnt(n), seen(n);
        FOR(i, 0, n) {
            cin >> a[i];
            ++cnt[a[i]-1];
            seen[a[i]-1] = 1;
        }
        if (accumulate(seen.begin(), seen.end(), 0LL) == 1) {
            for (int i : a) cout << i << ' ';
            cout << '\n';
            continue;
        }

        vi ones, mores;
        FOR(i, 0, n) {
            if (cnt[i] == 1) ones.push_back(i);
            else if (cnt[i] >= 2) mores.push_back(i);
        }
        
        // cout << '\n';
        // for (int i : cnt) cout << i << ' ';
        // cout << '\n';

        auto getone = [&]() {
            vi res;
            if (!ones.empty()) {
                res.push_back(ones.back());
                ones.pop_back();
            } else {
                FOR(j, 0, cnt[mores.back()]) res.push_back(mores.back());
                mores.pop_back();
            }
            return res;
        };

        vi res = getone();
        vi bot = getone();
        for (int i : mores) res.push_back(i);
        for (int i : bot) res.push_back(i);
        reverse(mores.begin(), mores.end());
        for (int i : mores) {
            FOR(j, 0, cnt[i]-1) {
                if (!ones.empty() && j != 0) {
                    res.push_back(ones.back());
                    ones.pop_back();
                }
                res.push_back(i);
            }
        }

        if (res.size() == n) {
            for (int i : res) cout << i+1 << ' ';
        } else {
            sort(a.begin(), a.end());
            for (int i : a) cout << i << ' ';
        }
        cout << '\n';
    }
}