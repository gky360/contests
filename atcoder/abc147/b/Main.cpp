/*
[abc147] B - Palindrome-philia
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

string S;

ll solve() {
    int N = S.size();
    ll ans = 0;
    for (int i = 0; i < N / 2; i++) {
        if (S[i] != S[N - i - 1]) {
            ans++;
        }
    }
    return ans;
}

int main() {
    cin >> S;

    cout << solve() << endl;

    return 0;
}
