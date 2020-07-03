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

main() {
    //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string s, t;
    cin >> s >> t;
    int n=s.size(), m=t.size();

    const int BIG = 410;
    vector<vector<vb>> seen(n+1, vector<vb>(m+1, vb(BIG)));
    vector<vector<vector<tiii>>> par(n+1, vector<vector<tiii>>(m+1, vector<tiii>(BIG)));
    
    queue<tuple<int,int,int,int>> q;
    q.push({0, 0, 0, 0});
    seen[0][0][0] = true;
    while (!q.empty()) {
        int i,j,bal,len;
        tie(i,j,bal,len) = q.front();
        q.pop();

        if (i==n && j==m && bal==0) {
            int ii=i,jj=j,newbal=bal;
            string res(len, ' ');
            int cnt = len-1;
            while (cnt>=0) {
                tie(ii,jj,newbal) = par[ii][jj][newbal];
                if (newbal<bal) res[cnt] = '(';
                else res[cnt] = ')';
                --cnt;
                i=ii;
                j=jj;
                bal=newbal;
            }
            cout << res;
            break;
        }


        for (char c : "()") {
            int ii=i,jj=j,newbal=bal-1;
            if (i<n && s[i] == c) ++ii;
            if (j<m && t[j] == c) ++jj;
            if (c=='(') newbal += 2;
            if (newbal >= 0 && !seen[ii][jj][newbal]) {
                q.push({ii,jj,newbal,len+1});
                seen[ii][jj][newbal] = true;
                par[ii][jj][newbal] = {i,j,bal};
            }
        }
    }
}