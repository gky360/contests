/*
[past202012-open] B - Overwrite
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

int N;
string S;

string solve() {
    string T;
    for (char c : S) {
        for (auto iter = T.find(c); iter != string::npos; iter = T.find(c)) {
            T.erase(iter, 1);
        }
        T.push_back(c);
    }

    return T;
}

int main() {
    cin >> N;
    cin >> S;

    cout << solve() << endl;

    return 0;
}
