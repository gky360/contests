/*
[abc125] C - GCD on Blackboard
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;

int N;
int A[MAX_N];
int l[MAX_N + 1], r[MAX_N + 1];

int gcd(int a, int b) {
    while (b > 0) {
        swap(b, a %= b);
    }
    return a;
}

ll solve() {
    l[0] = 0;
    for (int i = 0; i < N; i++) {
        l[i + 1] = gcd(l[i], A[i]);
    }
    r[N] = 0;
    for (int i = N; i > 0; i--) {
        r[i - 1] = gcd(r[i], A[i - 1]);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, gcd(l[i], r[i + 1]));
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
