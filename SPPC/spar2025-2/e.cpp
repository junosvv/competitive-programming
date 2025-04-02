#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define ROF(i, a, b) for (int i=(a); i>(b); --i)
#define vi vector<int>
#define vvi vector<vi>
#define vs vector<string>

signed main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    vs S, A, X;
    FOR(i, 0, n) {
        string c;
        int x;
        cin >> c >> x;
        string card = c + " " + to_string(x);
        if (c == "*" && !(x&1)) S.push_back(card);
        else if (c == "+" && (x&1)) A.push_back(card);
        else X.push_back(card);
    }
    int p;
    cin >> p;

    if (S.empty()) {
        p ^= (A.size()&1);
        for (string& card : A) X.push_back(card);
        if (p) {
            cout << "me" << endl;
        } else {
            cout << "you" << endl;
            string c, x;
            cin >> c >> x;
            c += " " + x;
            X.erase(remove(X.begin(), X.end(), c), X.end());
        }

        while (!X.empty()) {
            cout << X.back() << endl;
            X.pop_back();
            if (X.empty()) break;
            string c, x;
            cin >> c >> x;
            c += " " + x;
            X.erase(remove(X.begin(), X.end(), c), X.end());
        }
    } else if (S.size() == 1 && (A.size()&1)) {
        for (string& card : A) X.push_back(card);
        cout << "me" << endl;
        X.push_back(S[0]);
        while (!X.empty()) {
            cout << X.back() << endl;
            X.pop_back();
            if (X.empty()) break;
            string c, x;
            cin >> c >> x;
            c += " " + x;
            X.erase(remove(X.begin(), X.end(), c), X.end());
        }
    } else {
        cout << "you" << endl;
        for (string& card : S) X.push_back(card);
        while (!(X.empty() && A.empty())) {
            string c;
            int x;
            cin >> c >> x;
            string card = c + " " + to_string(x);

            if (c == "+" && (x&1)) A.erase(remove(A.begin(), A.end(), card), A.end());
            else X.erase(remove(X.begin(), X.end(), card), X.end());

            if (X.empty() && A.empty()) break;

            if (X.size() == 0 || (A.size()&1)) {
                cout << A.back() << endl;
                A.pop_back();
            } else {
                cout << X.back() << endl;
                X.pop_back();
            }
        }
    }
}