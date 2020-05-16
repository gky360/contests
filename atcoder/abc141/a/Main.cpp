/*
[abc141] A - Weather Prediction
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

string S;

string solve() {
    if (S == "Sunny") {
        return "Cloudy";
    }
    if (S == "Cloudy") {
        return "Rainy";
    }
    return "Sunny";
}

int main() {
    cin >> S;

    cout << solve() << endl;

    return 0;
}
