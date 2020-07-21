/*
[past201912-open] A - 2 倍チェック / Is It a Number?
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
    int n = 0;
    for (int i = 0, p = 1; i < 3; i++, p *= 10) {
        char c = S[3 - i - 1];
        if (!isdigit(c)) {
            return "error";
        }
        n += (c - '0') * p;
    }

    return to_string(n * 2);
}

int main() {
    cin >> S;

    cout << solve() << endl;

    return 0;
}
