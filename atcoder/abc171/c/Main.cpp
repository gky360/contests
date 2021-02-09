/*
[abc171] C - One Quadrillion and One Dalmatians
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

ll N;

string solve() {
    int len = 1;
    for (ll p = 26; N > p; p *= 26) {
        N -= p;
        len++;
    }

    N--;
    string ans;
    REP(i, len) {
        ans.push_back('a' + (N % 26));
        N /= 26;
    }
    reverse(ALL(ans));
    return ans;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
