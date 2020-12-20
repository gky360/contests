/*
[abc165] A - We Love Golf
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int K;
int A, B;

ll solve() { return B / K * K >= A; }

int main() {
    cin >> K;
    cin >> A >> B;

    cout << (solve() ? "OK" : "NG") << endl;

    return 0;
}
