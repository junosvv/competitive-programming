#include <bits/stdc++.h>
using namespace std;

typedef long long lglg;

int main() {
    ios::sync_with_stdio(0);//, cin.tie(0), cout.tie(0);

	string msg; cin >> msg;
	string result = "Yes";
	for (int i=0; i<msg.size(); i+=2) {
		if (msg[i] == 'L') {
			result = "No";
			break;
		}
	}
	if (result == "Yes") {
		for (int i=1; i<msg.size(); i+=2) {
			if (msg[i] == 'R') {
				result = "No";
				break;
			}
		}
	}
	cout << result;
}