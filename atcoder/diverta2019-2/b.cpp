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
    pair<int,int> coords[n];
    REP(i, n) {
        int x,y;
        cin >> x >> y;
        coords[i] = {x, y};
    }
    sort(coords, coords+n);

    if (n == 1) {
        cout << 1;
        return 0;
    }

    int best = -1;
    for (auto a : coords) {
        for (auto b : coords) {
            if (a == b) continue;
            int p = a.first-b.first, q=a.second-b.second;
            int saved = 0;
            for (auto x : coords) {
                for (auto y : coords) {
                    if (y.first-x.first == p && y.second-x.second == q) {
                        ++saved;
                    }
                }
            }
            if (best == -1 || n-saved < best) best = n-saved;
        }
    }
    cout << best;
}