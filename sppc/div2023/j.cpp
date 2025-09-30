#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vs vector<string>


map<ll,ll> mp;
map<ll,ll> old_map;
set<ll> update;
bool sleep_mode;
signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    sleep_mode = false;
    for (ll i = 0; i < n; i++) {
        string s; cin >> s;
        if (s == "WASHSOCK") {
            ll x; cin >> x;
            mp[x]--;
            update.insert(x);
            if (!sleep_mode) cout << "SOCK " << x << " " << mp[x] << "\n";
        }
        if (s == "WEARSOCK") {
            ll x; cin >> x;
            mp[x]++;
            update.insert(x);
            if (!sleep_mode) cout << "SOCK " << x << " " << mp[x] << "\n";
        }
        if (s == "SLEEP") {
            old_map = mp;
            sleep_mode = true;
        }
        if (s == "WAKE") {
            sleep_mode = false;
            for (ll x : update) {
                if (mp[x] == old_map[x]) continue;
                cout << "SOCK " << x << " " << mp[x] << "\n";
            }
        }
    }
}