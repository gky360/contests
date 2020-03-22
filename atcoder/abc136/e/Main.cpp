/*
[abc136] E - Max GCD
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 500;

int N, K;
int A[MAX_N];

bool can(int m) {
    int r[MAX_N];
    for (int i = 0; i < N; i++) {
        r[i] = A[i] % m;
    }
    sort(r, r + N);

    int rs[MAX_N + 1];
    rs[0] = 0;
    for (int i = 0; i < N; i++) {
        rs[i + 1] = rs[i] + r[i];
    }

    for (int i = 0; i <= N; i++) {
        if (max((ll)rs[i], (ll)m * (N - i) - (rs[N] - rs[i])) <= K) {
            return true;
        }
    }
    return false;
}

ll solve() {
    int s = 0;
    for (int i = 0; i < N; i++) {
        s += A[i];
    }

    int ans = 1;
    for (int i = 1; i * i <= s; i++) {
        if (s % i == 0) {
            if (can(i)) {
                ans = max(ans, i);
            }
            if (can(s / i)) {
                ans = max(ans, s / i);
            }
        }
    }

    return ans;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
