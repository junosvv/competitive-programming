#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    int n;
    cin >> n;
    vi par(n), t(n), s(n), g(n), meds;
    vvi G(n);
    int mxenemy = 0;
    FOR(i, 1, n) {
        cin >> par[i] >> t[i] >> s[i] >> g[i];
        if (t[i] == 1) {
            t[i] = 0;
            mxenemy = max(mxenemy, s[i]);
        } else {
            meds.push_back(i);
            t[i] = meds.size();
        }
        --par[i];
        G[par[i]].push_back(i);
    }
    if (mxenemy == 0) {
        cout << "Yes";
        exit(0);
    }
    int m = meds.size();

    vi dp(1<<m);
    dp[0] = 1;
    vector<priority_queue<pii>> pqs(1<<m);
    vector<set<int>> seenmedsvec(1<<m);

    auto& pq = pqs[0];
    auto& seenmeds = seenmedsvec[0];
    pq.emplace(0, 0);

    while (!pq.empty()) {
        int cost, u;
        tie(cost, u) = pq.top();
        cost = -cost;
        if (cost > dp[0]) break;
        pq.pop();
        dp[0] += g[u];
        for (int v : G[u]) {
            if (t[v] == 0) pq.emplace(-s[v], v);
            else seenmeds.insert(t[v]-1);
        }
    }

    FOR(mask, 0, 1<<m) if (dp[mask]) {
        // cout << "mask " << mask << " has " << dp[mask] << '\n';
        for (int k : seenmedsvec[mask]) {
            priority_queue<pii> pq = pqs[mask];
            set<int> seenmeds = seenmedsvec[mask];
            if (dp[mask] > (mxenemy-1)/g[meds[k]]) {
                cout << "Yes";
                exit(0);
            }
            int strength = dp[mask] * g[meds[k]];
            seenmeds.erase(k);
            pq.emplace(0, meds[k]);
            // cout << "taking med " << g[meds[k]] << ", new strength " << strength << '\n';

            while (!pq.empty()) {
                int cost, u;
                tie(cost, u) = pq.top();
                cost = -cost;
                if (cost > strength) break;
                pq.pop();
                // cout << "proc " << u+1 << '\n';
                if (!t[u]) strength += g[u];
                for (int v : G[u]) {
                    if (t[v] == 0) pq.emplace(-s[v], v);
                    else seenmeds.insert(t[v]-1);
                }
            }
            // cout << "achieved " << strength << "\nseenmeds: ";
            // for (int i : seenmeds) cout << g[meds[i]] << ' ';
            // cout << '\n';

            int newmask = mask | 1<<k;
            if (strength > dp[newmask]) {
                dp[newmask] = strength;
                swap(pqs[newmask], pq);
                swap(seenmedsvec[newmask], seenmeds);
            }
        }
    }
    if (*max_element(dp.begin(), dp.end()) >= mxenemy) cout << "Yes";
    else cout << "No";
}