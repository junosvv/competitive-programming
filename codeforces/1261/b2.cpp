#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, l, r) for (__typeof(l) i = (l); i != (r); (l)<(r)?++i:--i)
#define popcount __builtin_popcountll

const int INF = 1LL<<60;
const int MOD = 998244353;

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

string bin_string(int x) {
    string result(64, ' ');
    for (signed i=63; i>=0; --i) result[63-i] = '0'+((x&1LL<<i)!=0);
    return result;
}

int powa(int base, int exp) {
    if (exp<=0) return 1;
    if (base<=0) return 0;
    int val = powa(base, exp/2);
    val = (val*val)%MOD;
    if (exp%2==1) {
        val *= base;
        val %= MOD;
    }
    return val;
}

int n;
const int BIGN = 300000;
int tree[BIGN<<1] = {};
int a[BIGN], res[BIGN];
vector<pair<int,int>> pullfrom;

void rectify(int x) {
    while (x >>= 1) {
        tree[x] = tree[x<<1] + tree[x<<1|1];
    }
}

int gofind(int x, int cur) {
    if (cur >= n) return a[cur-n];
    cur <<= 1;
    if (cur >= n) {
        if (x == 1 && tree[cur] > 0) return gofind(1, cur);
        return gofind(1, cur|1);
    } 
    if (tree[cur] >= x) return gofind(x, cur);
    return gofind(x-tree[cur], cur|1);
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n;
    REP(i, 0, n) {
        cin >> a[i];
        pullfrom.push_back({-a[i], i});
    }
    sort(pullfrom.begin(), pullfrom.end());
    int oldn = n;
    n = 1; while (n<oldn) n <<= 1;
    int m;
    cin >> m;
    tuple<int,int,int> reqs[m];
    REP(i, 0, m) {
        int k, pos;
        cin >> k >> pos;
        reqs[i] = {k, pos, i};
    }
    sort(reqs, reqs+m);
    REP(i, 0, m) {
        int k, pos, ind;
        tie(k, pos, ind) = reqs[i];
        while (tree[1] < k) {
            int x, j;
            tie(x, j) = pullfrom[tree[1]];
            tree[n+j] = -x;
            ++tree[(n+j)>>1];
            rectify((n+j)>>1);
        }
        res[ind] = gofind(pos, 1);
        // cout << k << " " << pos << ": " << to_string(tree, n<<1) << " " << res[ind] << '\n';
    }
    REP(i, 0, m) cout << res[i] << '\n';
}