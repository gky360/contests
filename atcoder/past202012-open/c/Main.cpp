/*
[past202012-open] C - Hexatridecimal
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

string solve() {
    if (N == 0) return "0";
    string ans;
    for (int n = N; n > 0; n /= 36) {
        int k = n % 36;
        ans.push_back(k <= 9 ? ('0' + k) : ('A' + (k - 10)));
    }
    reverse(ALL(ans));

    return ans;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
