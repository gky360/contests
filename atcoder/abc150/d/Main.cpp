/*
[abc150] D - Semi Common Multiple
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;

int N, M;
int A[MAX_N];

ll gcd(ll a, ll b) {
    while (b > 0) {
        swap(b, a %= b);
    }
    return a;
}

ll lcm(ll a, ll b) {
    ll d = gcd(a, b);
    return a * b / d;
}

ll solve() {
    ll l = 1;
    for (int i = 0; i < N; i++) {
        l = lcm(l, A[i] / 2);
        if (l > M) {
            return 0;
        }
    }
    for (int i = 0; i < N; i++) {
        if ((l / (A[i] / 2)) % 2 == 0) {
            return 0;
        }
    }

    int ans = (M - l) / (2 * l) + 1;

    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
