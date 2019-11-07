/*
[abc126] B - YYMM or MMYY
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int S;

bool maybe_month(int a) { return 0 < a && a <= 12; }

string solve() {
    bool a = maybe_month(S / 100);
    bool b = maybe_month(S % 100);
    if (a && b) {
        return "AMBIGUOUS";
    }
    if (!a && !b) {
        return "NA";
    }
    if (a) {
        return "MMYY";
    }
    return "YYMM";
}

int main() {
    cin >> S;

    cout << solve() << endl;

    return 0;
}
