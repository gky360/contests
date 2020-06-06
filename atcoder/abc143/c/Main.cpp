/*
[abc143] C - Slimes
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
    S.push_back('_');

    ll ans = 0;
    for (int i = 1; i <= N; i++) {
        if (S[i - 1] != S[i]) {
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
