#include <bits/stdc++.h>
using namespace std;

typedef long long lglg;

int main() {
    ios::sync_with_stdio(0);//, cin.tie(0), cout.tie(0);

	string weather[3] = {"Sunny", "Cloudy", "Rainy"};
	string x; cin >> x;
	int n;
	for (int i=0; i<3; ++i) if (weather[i] == x) n = i;
	cout << weather[(n+1)%3];
}