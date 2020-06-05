/*
[abc143] B - TAKOYAKI FESTIVAL 2019
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 50;

int N;
int d[MAX_N];

ll solve() {
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            ans += d[i] * d[j];
        }
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> d[i];
    }

    cout << solve() << endl;

    return 0;
}
