/*
[past202010-open] B - 電卓
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

int X, Y;

string solve() {
    if (Y == 0) return "ERROR";
    int a = X * 100 / Y;
    stringstream ss;
    ss << a / 100 << '.' << setw(2) << setfill('0') << a % 100;
    return ss.str();
}

int main() {
    cin >> X >> Y;

    cout << solve() << endl;

    return 0;
}
