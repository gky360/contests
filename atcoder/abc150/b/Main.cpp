/*
[abc150] B - Count ABC
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int N;
string S;

ll solve() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (S.substr(i, 3) == "ABC") {
            ans++;
        }
    }

    return ans;
}

int main() {
    cin >> N;
    cin >> S;

    cout << solve() << endl;

    return 0;
}
