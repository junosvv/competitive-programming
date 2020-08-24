#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define popcount __builtin_popcountll

const int INF = 1LL<<60;
const int MOD = 1000000007;

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
string to_string(A x[], int n) {
    string result = "{";
    REP(i, 0, n) {
        if (i!=0) result += ", ";
        result += to_string(x[i]); 
    }
    return result + "}";
}

string bin_string(int x) {
    const int d = 64;
    string result(d, ' ');
    REP(i, d-1, -1) result[d-1-i] = '0'+((x&1LL<<i)!=0);
    return result;
}

vector<int> getZ(string s) {
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
    if (exp<=0) return 1;
    if (base<=0) return 0;
    int val = powa(base, exp>>1);
    val = val*val % MOD;
    if (exp&1) {
        val = val*base % MOD;
    }
    return val;
}

vector<vector<int>> getPref(vector<vector<int>> arr) {
    vector<vector<int>> pref(arr.size());
    REP(i, 0, arr.size()) {
        REP(j, 0, arr[i].size()) {
            int left=0, above=0, both=0;
            if (i != 0) above = pref[i-1][j];
            if (j != 0) {
                left = pref[i][j-1];
                if (i != 0) both = pref[i-1][j-1];
            }
            pref[i].push_back(arr[i][j] + left + above - both);
        }
    }
    return pref;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int r,c;
    cin >> r >> c;
    vector<vector<int>> arr(r);
    REP(i, 0, r) {
        string s;
        cin >> s;
        REP(j, 0, c) arr[i].push_back(s[j] == 'X');
    }
    vector<vector<int>> pref = getPref(arr);
    int t=-1;
    int upp=min(r, c);
    bool res[r][c];
    for (int b=upp; b>=1; b/=2) {
        while (t+b <= upp) {
            int square = (t+b+t+b+1)*(t+b+t+b+1);
            bool hastree[r][c] = {};
            vector<vector<int>> diff(r);
            REP(i, 0, r) REP(j, 0, c) diff[i].push_back(0);
            REP(i, t+b, r-t-b) {
                REP(j, t+b, c-t-b) {
                    int left = 0, above = 0, both = 0;
                    if (j-t-b-1 >= 0) left = pref[i+t+b][j-t-b-1];
                    if (i-t-b-1 >= 0) {
                        above = pref[i-t-b-1][j+t+b];
                        if (j-t-b-1 >= 0) both = pref[i-t-b-1][j-t-b-1];
                    }
                    hastree[i][j] = pref[i+t+b][j+t+b] - left - above + both == square;
                    if (hastree[i][j]) {
                        ++diff[i-t-b][j-t-b];
                        if (i+t+b+1<r) --diff[i+t+b+1][j-t-b];
                        if (j+t+b+1<c) {
                            --diff[i-t-b][j+t+b+1];
                            if (i+t+b+1<r) ++diff[i+t+b+1][j+t+b+1];
                        }
                    }
                }
            }
            vector<vector<int>> gener = getPref(diff);
            bool failed = false;
            REP(i, 0, r) {
                REP(j, 0, c) {
                    if ((gener[i][j] == 0) != (arr[i][j] == 0)) {
                        failed = true;
                        break;
                    }
                }
            }
            if (failed) break;
            REP(i, 0, r) REP(j, 0, c) res[i][j] = hastree[i][j];
            t += b;
        }
    }
    cout << t << '\n';
    REP(i, 0, r) {
        REP(j, 0, c) {
            if (res[i][j]) cout << 'X';
            else cout << '.';
        }
        cout << '\n';
    }
}