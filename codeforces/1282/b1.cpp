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
string to_string(string s) {return s;}
template <typename A, typename B>
string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ")";}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> t) { return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ", " + to_string(get<3>(t)) + ")";}
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
    const int d = 32;
    string result(d, ' ');
    for (int i=d-1; i>=0; --i) result[d-1-i] = '0'+((x&1LL<<i)!=0);
    return result;
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
    
    int T;
    cin >> T;
    while (T--) {
        int n, p, k;
        cin >> n >> p >> k;
        vi price(n);
        cin >> price;
        sort(price.begin(), price.end());

        vi arr(n);
        arr[0] = price[0];
        REP(i, 1, n) {
            if (i<k-1) arr[i] = price[i]+arr[i-1];
            else if (i==k-1) arr[i] = price[i];
            else arr[i] = price[i] + arr[i-k];
        }
        bool printed = false;
        RREP(i, n-1, -1) {
            if (arr[i] <= p) {
                if (i<k-1) {
                    int res = 0, cost=0;;
                    REP(i, 0, k-1) {
                        if (cost+price[i] > p) break;
                        cost += price[i];
                        ++res;
                    }
                    cout << res << '\n';
                }
                else cout << i+1 << '\n';
                printed = true;
                break;
            }
        }
        if (!printed) cout << "0\n";
    }
}