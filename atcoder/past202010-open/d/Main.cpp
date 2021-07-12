/*
[past202010-open] D - 分身
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

void solve() {
    vector<int> z = {0};
    if (S[0] == '#') z.push_back(0);
    for (char c : S) {
        if (c == '#') {
            if (z.back() != 0) z.push_back(0);
        } else {
            z.back()++;
        }
    }

    int m = *max_element(ALL(z));
    int x = z.front(), y = z.back();
    x += max(0, m - x - y);

    cout << x << " " << y << endl;
}

int main() {
    cin >> N;
    cin >> S;

    solve();

    return 0;
}
