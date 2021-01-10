/*
[abc168] B - ... (Triple Dots)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int K;
string S;

string solve() {
    if ((int)S.length() <= K) {
        return S;
    }
    return S.substr(0, K) + "...";
}

int main() {
    cin >> K;
    cin >> S;

    cout << solve() << endl;

    return 0;
}
