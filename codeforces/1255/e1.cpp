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
string to_string(A x[], lglg n) {
    string result = "{";
    for (lglg i=0; i<n; ++i) {
        if (i!=0) result += ", ";
        result += to_string(x[i]); 
    }
    return result + "}";
}

lglg n, k, best = -1;
vector<lglg> boxes;

void check(lglg d) {
	lglg result = 0;
	for (lglg b=0; b<boxes.size()/d; ++b) {
		lglg comp[d];
		for (lglg i=0; i<d; ++i) comp[i] = boxes[b*d+i];
		sort(comp, comp+d);
		for (lglg i=0; i<d; ++i) result += abs(comp[i]-comp[d/2]);
	}
	if (best == -1 || result < best) best = result;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	for (lglg i=0; i<n; ++i) {
		lglg x; cin >> x;
		if (x==1) boxes.push_back(i);
	}
	k = boxes.size();
	
	if (k == 1) cout << -1;
	else {
		for (lglg d=2; d*d<=k; ++d) {
			if (k%d==0) {
				while (k%d == 0) k /= d;
				check(d);
			}
		}
		if (k > 1) check(k);
		cout << best;
	}
}