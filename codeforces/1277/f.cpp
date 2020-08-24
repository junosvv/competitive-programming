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
    const int d = 64;
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

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;
    map<int,int> occ;
    REP(i, 0, n) {
        int x;
        cin >> x;
        ++occ[x];
    }
    priority_queue<pii> pq;
    for (auto pr : occ) pq.push({pr.second, pr.first});

    priority_queue<pii> pqcopy = pq;
    vi req(n+1);
    RREP(i, n, 0) {
        req[i] = pqcopy.top().first;
        if (req[i] > 1) pqcopy.push({req[i]-1, pqcopy.top().second});
        pqcopy.pop();
    }

    vector<pii> possAnswers;
    for (int d=1; d*d<=n; ++d) {
        int k=d-1;
        for (int b=n/d; b>=1; b/=2) {
            while (k+b<=n/d && req[d*(k+b)] <= d) k += b;
        }
        if (k!=d-1) possAnswers.push_back({d, k});
    }
    int h=0, w=0;
    for (auto pr : possAnswers) if (pr.first*pr.second > h*w) {
        h=pr.first;
        w=pr.second;
    }

    cout << h*w << '\n' << h << ' ' << w << '\n';
    RREP(r, n, h*w) {
        if (pq.top().first > 1) pq.push({pq.top().first-1, pq.top().second});
        pq.pop();
    }
    int i=0, j=0;
    vector<vi> res(h, vi(w));
    while (!pq.empty()) {
        int rpt=pq.top().first, num=pq.top().second;
        pq.pop();
        REP(s, 0, rpt) {
            res[j][(i+j)%w] = num;
            ++j;
            if (j==h) {
                j=0;
                ++i;
            }
        }
    }
    REP(i, 0, h) {
        REP(j, 0, w) cout << res[i][j] << ' ';
        cout << '\n';
    }
}