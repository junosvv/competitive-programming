#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define t3i tuple<int,int,int>

// signed main() {
//     ios::sync_with_stdio(0), cin.tie(0);

//     int n, L;
//     cin >> n >> L;
//     vi value(n+1), size(n+1);
//     FOR(i, 1, n+1) cin >> value[i] >> size[i];

//     const int BIG = 21;
//     vvi sparse(n+1, vi(BIG));
//     FOR(i, 1, n+1) sparse[i][0] = value[i];
//     FOR(k, 1, BIG) FOR(i, 0, n+1-(1<<k-1)) sparse[i][k] = max(sparse[i][k-1], sparse[i+(1<<k-1)][k-1]);
//     vi lg(n+1);
//     FOR(i, 2, n+1) lg[i] = 1 + lg[i/2];

//     auto query = [&](int l, int r) {
//         assert(l <= r);
//         int k = lg[r-l+1];
//         return max(sparse[l][k], sparse[r+1-(1<<k)][k]);
//     };

//     vi dp(n+1);
//     multiset<int> posses;
//     deque<pii> dq;
//     int l = 1, sz = 0;
//     FOR(i, 1, n+1) {
//         sz += size[i];
//         while (sz > L) sz -= size[l++];

//         while (!dq.empty() && dq.front().second < l) {
//             int j = dq.front().second;
//             posses.erase(posses.find(query(j, i-1) + dp[j-1]));
//             dq.pop_front();
//         }
//         if (dq.empty() || l < dq.front().second) {
//             int mx = query(l, i);
//             dq.emplace_front(mx, l);
//             posses.insert(mx + dp[l-1]);
//         }
//         int j = i;
//         while (!dq.empty() && dq.back().first <= value[i]) {
//             j = dq.back().second;
//             int mx = j == i ? value[i] : query(j, i-1);
//             posses.erase(posses.find(mx + dp[j-1]));
//             dq.pop_back();
//         }
//         if (dq.empty() || j > dq.back().second) {
//             dq.emplace_back(value[i], j);
//             posses.insert(value[i] + dp[j-1]);
//         }
//         dp[i] = *posses.begin();
//     }
    
//     cout << dp[n];
// }


signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    while (true) {
        int n=20, L=rand()%100+1;
        cin >> n >> L;
        vi value(n+1), size(n+1);
        FOR(i, 1, n+1) {
            value[i] = rand()%100;
            size[i] = rand()%L+1;
            cin >> value[i] >> size[i];
        }

        const int BIG = 21;
        vvi sparse(n+1, vi(BIG));
        FOR(i, 1, n+1) sparse[i][0] = value[i];
        FOR(k, 1, BIG) FOR(i, 0, n+1-(1<<k-1)) sparse[i][k] = max(sparse[i][k-1], sparse[i+(1<<k-1)][k-1]);
        vi lg(n+1);
        FOR(i, 2, n+1) lg[i] = 1 + lg[i/2];

        auto query = [&](int l, int r) {
            assert(l <= r);
            int k = lg[r-l+1];
            return max(sparse[l][k], sparse[r+1-(1<<k)][k]);
        };

        vi dp(n+1);
        multiset<int> posses;
        deque<pii> dq;
        int l = 1, sz = 0;
        FOR(i, 1, n+1) {
            sz += size[i];
            while (sz > L) sz -= size[l++];

            while (!dq.empty() && dq.front().second < l) {
                int j = dq.front().second;
                posses.erase(posses.find(query(j, i-1) + dp[j-1]));
                dq.pop_front();
            }
            if (dq.empty() || l < dq.front().second) {
                int mx = query(l, i);
                dq.emplace_front(mx, l);
                posses.insert(mx + dp[l-1]);
            }
            int j = i;
            while (!dq.empty() && dq.back().first <= value[i]) {
                j = dq.back().second;
                int mx = j == i ? value[i] : query(j, i-1);
                posses.erase(posses.find(mx + dp[j-1]));
                dq.pop_back();
            }
            if (dq.empty() || j > dq.back().second) {
                dq.emplace_back(value[i], j);
                posses.insert(value[i] + dp[j-1]);
            }
            dp[i] = *posses.begin();
        }

        vi dp2(n+1, 1e18);
        dp2[0] = 0;
        FOR(i, 1, n+1) {
            int mx = value[i], sz = 0;
            ROF(j, i, 0) {
                mx = max(mx, value[j]);
                sz += size[j];
                if (sz > L) break;
                dp2[i] = min(dp2[i], dp2[j-1] + mx);
            }
        }

        // for (int i : dp) cout << i << ' ';
        // cout << endl;
        // for (int i : dp2) cout << i << ' ';
        // cout << endl;
        // exit(0);

        cout << "wtf\n";
        cout << n << ' ' << L << '\n';
        FOR(i, 1, n+1) cout << value[i] << ' ' << size[i] << '\n';
        cout << endl;

        if (dp != dp2) {
            cout << "wtf\n";
            cout << n << ' ' << L << '\n';
            FOR(i, 1, n+1) cout << value[i] << ' ' << size[i] << '\n';
            cout << "dp: ";
            for (int i : dp) cout << i << ' ';
            cout << "\ndp2: ";
            for (int i : dp2) cout << i << ' ';
            cout << endl;
            exit(0);
        }
    }
}