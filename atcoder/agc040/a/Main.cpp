/*
[agc040] A - ><
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 5e5;

string S;
int N;

ll solve() {
    N = S.size() + 1;
    int l[MAX_N], r[MAX_N];
    l[0] = 0;
    for (int i = 1; i < N; i++) {
        l[i] = (S[i - 1] == '<') ? l[i - 1] + 1 : 0;
    }
    r[N - 1] = 0;
    for (int i = N - 2; i >= 0; i--) {
        r[i] = (S[i] == '>') ? r[i + 1] + 1 : 0;
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += max(l[i], r[i]);
    }
    return ans;
}

int main() {
    cin >> S;

    cout << solve() << endl;

    return 0;
}
