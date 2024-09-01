#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define vi vector<int>
#define vvi vector<vi>

int mode(int a, int b, int c) {
    if (a==b) return a;
    if (a==c) return a;
    if (b==c) return b;
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cout << "1 0 0" << endl;
    int a,b,c;
    cin >> a;
    cout << "0 1 0" << endl;
    cin >> b;
    cout << "0 0 1" << endl;
    cin >> c;
    
    cout << "1 1 2" << endl;
    int ab2c, abc;
    cin >> ab2c;
    cout << "1 1 1" << endl;
    cin >> abc;
    
    int na = abc - b -c;
    int nb = abc - a - c;
    int nc = ab2c - abc;
    if (a+b+c == abc || a+b+2*c == ab2c) {
        cout << a << " " << b << " " << c << endl;
    } else if (na + b + 2*c == ab2c && a!= na && b==nb && c==nc) {
        cout << na << " " << b << " " << c << endl;
    } else if (a + nb + 2*c == ab2c && b!=nb && a==na && c==nc) {
        cout << a << " " << nb << " " << c << endl;
    } else if (a + b + 2*c == ab2c && c!=nc && a==na && b==nb) {
        cout << a << " " << b << " " << nc << endl;
    }
    
}