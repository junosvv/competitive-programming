#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>
#define tiii tuple<int,int,int>
#define tiiii tuple<int,int,int,int>
#define popcount __builtin_popcountll

const int INF = 1LL<<60;
const int MOD = 1000000007;

template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {
    return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> t) {
    return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + ")";
}
template <typename A>
string to_string(vector<A> v) {
    bool first = true;
    string result = "[";
    for (A i : v) {
        if (!first) result += ", ";
        first = false;
        result += to_string(i); 
    }
    return result + "]";
}

string bin_string(int x) {
    const int d = 5;
    string result(d, ' ');
    RREP(i, d-1, -1) result[d-1-i] = '0'+((x&1LL<<i)!=0);
    return result;
}

vi getZ(string s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    REP(i, 1, n) {
        z[i] = max(0LL, min(z[i-x], y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            x = i;
            y = i+z[i];
            ++z[i];
        }
    }
    return z;
}

int powa(int base, int exp) {
    int res = 1;
    while (exp) {
        if (exp&1) res = res*base % MOD;
        base = base*base % MOD;
        exp >>= 1;
    }
    return res;
}

int k, avg=0;
vi boxsums;
vector<vi> boxes;
map<int,int> loc;
bool done = false;
vb dp;

void dfs(int mask, vector<tiii> &res) {
    if (dp[mask]) return;
    dp[mask] = true;
    int cur=0; while (mask&1<<cur) ++cur;
    if (cur==k) {
        done = true;
        cout << "Yes\n";
        sort(res.begin(), res.end());
        for (auto pr : res) cout << get<1>(pr) << ' ' << get<2>(pr) << '\n';
        return;
    }
    if (boxsums[cur]==avg) {
        res.push_back({cur, boxes[cur][0], cur+1});
        dfs(mask|1<<cur, res);
        return;
    }
    int mask0 = mask;
    int cur0 = cur;
    int rsize = res.size();
    for (int u : boxes[cur0]) {
        int want=u;
        while (true) {
            mask |= 1<<cur;
            want = want+avg-boxsums[cur];
            if (want==u) {
                res.push_back({cur0, u, cur+1});
                dfs(mask, res);
                if (done) return;
            }
            if (!loc.count(want) || mask&1<<loc[want]) break;
            int cur1 = cur;
            cur = loc[want];
            res.push_back({cur, want, cur1+1});
        }
        mask = mask0;
        cur = cur0;
        res.resize(rsize);
    }
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> k;
    boxes.resize(k);
    boxsums.resize(k);
    REP(i, 0, k) {
        int sz;
        cin >> sz;
        boxes[i].resize(sz);
        REP(j, 0, sz) {
            cin >> boxes[i][j];
            boxsums[i] += boxes[i][j];
            loc[boxes[i][j]] = i;
        }
        avg += boxsums[i];
    }
    if (avg%k) {
        cout << "No";
        return 0;
    }
    avg /= k;
    dp.resize(1<<k);
    vector<tiii> res;
    dfs(0, res);
    if (!done) cout << "No";
}
