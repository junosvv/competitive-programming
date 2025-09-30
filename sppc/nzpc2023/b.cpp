#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    vector<string> reasons = {"$50 fine.", "Use card.", "Doubles."};
    ll a, b;
    for (int i = 0; i < 3; i++) {
        cin >> a >> b;
        if (a == b) {
            cout << reasons[2] << " Move forward " << (ll)(a + b) << " squares." << endl;
            exit(0);
        }
    }
    string letter;
    cin >> letter;
    if (letter == "y") {
        cout << reasons[1] << " Move forward " << (ll)(a + b) << " squares.\n";
    }
    else {
        cout << reasons[0] << " Move forward " << (ll)(a + b) << " squares.\n";
    }
    
}