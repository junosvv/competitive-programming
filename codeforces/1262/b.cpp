#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, n) for (int i=0; i<(n); ++i)
#define IREP(i, n) for (int i=1; i<=(n); ++i)
#define popcount __builtin_popcountll

const int INF = 1LL<<60;

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

template <typename A>
string to_string(A x[], signed n) {
    string result = "{";
    for (signed i=0; i<n; ++i) {
        if (i!=0) result += ", ";
        result += to_string(x[i]); 
    }
    return result + "}";
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n+1];
        IREP(i, n) cin >> a[i];

        bool seen[n+1] = {};
        bool failed = false;
        vector<int> res;
        int cnt = 1;
        int prev = -1;
        IREP(i, n) {
            if (a[i] < prev) {
                failed = true;
                break;
            }
            if (a[i] == prev) {
                while (seen[cnt]) ++cnt;
                if (cnt > a[i]) {
                    failed = true;
                    break;
                }
                res.push_back(cnt);
                seen[cnt] = true;
            } else {
                res.push_back(a[i]);
                seen[a[i]] = true;
            }
            prev = a[i];
        }
        if (failed) cout << -1;
        else REP(i,n) cout << res[i] << " ";
        cout << '\n';
    }
}