#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, n) for (int i=0; i<(n); ++i)
#define IREP(i, n) for (int i=1; i<=(n); ++i)

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
    
    int n,m;
    cin >> n >> m;
    char s[n+1];
    cin >> s;
    int nextZero[n+1], z;
    for (int i=0; i<=n; ++i) {
        if (s[i] == '0') z = i;
        nextZero[i] = z;
    }

    pair<int,int> dp[n+1];
    bool failed = false;
    for (int x=n-1; x>=0; --x) {
        if (s[x] == '1') continue;
        int leap = nextZero[min(x+m, n)];
        if (leap == x) {
            cout << -1;
            failed = true;
            break;
        }

        int keep = dp[leap].second;

        int k=leap;
        for (int b=m; b>=1; b/=2) {
            while (k-b>x) {
                int check = nextZero[k-b];
                if (check <= x || dp[check].second != keep) break;
                k = check;
            }
        }
        dp[x] = {k-x, dp[k].second+1};
    }
    if (!failed) {
        int x = 0;
        while (x != n) {
            cout << dp[x].first << " ";
            x += dp[x].first;
        }
    }
}