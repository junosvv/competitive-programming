#include <bits/stdc++.h>
using namespace std;
 
typedef long long lglg;

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
    for (int i=0; i<n; ++i) {
        if (i!=0) result += ", ";
        result += to_string(x[i]); 
    }
    return result + "}";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int T; cin >> T;
	while (T--) {
		int n, m; cin >> n >> m;
		pair<int,int> weight[n]; for (int i=0; i<n; ++i) {
			int x; cin >> x;
			weight[i] = {x,i};
		}
		sort(weight, weight+n);

		if (n == 2 || m < n) cout << "-1\n";
		else {
			int cost = 0;
			vector<int> outA, outB;

			for (int i=0; i<n; ++i) {
				outA.push_back(weight[i].second);
				outB.push_back(weight[(i+1)%n].second);
				cost += weight[i].first + weight[(i+1)%n].first;
			}
			for (int i=n; i<m; ++i) {
				outA.push_back(weight[0].second);
				outB.push_back(weight[1].second);
				cost += weight[0].first + weight[1].first;
			}

			cout << cost << '\n';
			for (int i=0; i<outA.size(); ++i) cout << outA[i]+1 << " " << outB[i]+1 << '\n';
		}
	}
}