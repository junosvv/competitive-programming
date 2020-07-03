#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, l, r) for (int i=(l); i<(r); ++i)
#define RREP(i, r, l) for (int i=(r); i>(l); --i)
#define vi vector<int>
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

int n;
vi box;

int check(int k) {
    vi newbox;
    int cum = 0;
    REP(i, 0, n) {
        if (cum+box[i]%k >= k) {
            newbox.push_back(k-cum);
            int val = box[i]%k-k+cum;
            if (val!=0) newbox.push_back(val);
            cum += box[i];
            cum %= k;
        } else {
            cum += box[i]%k;
            newbox.push_back(box[i]%k);
        }
    }
    int n = newbox.size();
    cum = 0;
    int prevcum = 0;
    vi goodspots;
    REP(pos, 0, n) {
        cum += newbox[pos];
        if (cum-prevcum > k/2) {
            prevcum += k;
            goodspots.push_back(pos);
        }
    }
    int cost = 0;
    int left = 0;
    REP(pos, 0, n) {
        if (left == goodspots.size()) break;
        if (newbox[pos]%k==0) continue;
        int toMove = min(k-newbox[goodspots[left]], newbox[pos]);
        int dist = abs(pos-goodspots[left]);
        cost += toMove*dist;
        newbox[pos] -= toMove;
        newbox[goodspots[left]] += toMove;
        if (newbox[goodspots[left]] == k) ++left;
    }
    return cost;
}

main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n;
    box.resize(n);
    cin >> box;
    
    int sum = accumulate(box.begin(), box.end(), 0LL);
    int res = INF;
    int k = 2;
    while (k*k <= sum) {
        if (sum%k == 0) {
            res = min(res, check(k));
            while (sum%k == 0) sum /= k;
        }
        ++k;
    }
    if (sum > 1) res = min(res, check(sum));
    if (res == INF) cout << -1;
    else cout << res;
}