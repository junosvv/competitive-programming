#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, n) for (int i=0; i<(n); ++i)

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
    
    int n;
    cin >> n;
    int x[n+1] = {};

    vector<int> occ[300];

    for (int d=2; d<=n; ++d) {
        if (x[d]) continue;
        for (int i=d; i<=n; i*=d) x[d] += n/i;
        REP(i, x[d]+1) occ[i].push_back(d);
        for (int u=2*d; u<=n; u+=d) x[u] = -1;
    }

    int res = 0;
    vector<int> nice = {2, 4, 14, 24};
    for (int i : occ[24]) for (int j : occ[2]) if (i != j) res += 2;
    for (int i : occ[14]) for (int j : occ[4]) if (i != j) res += 2;
    for (int i : occ[2]) for (int j : occ[4]) for (int k : occ[4]) if (i != j && j != k && i != k) ++res;
    cout << res/2 + occ[74].size();
}