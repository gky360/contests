/*
[arc104] C - Fair Elevator
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 100;

int N;
int A[MAX_N], B[MAX_N];
int m[2 * MAX_N];
bool dp[MAX_N + 1];

bool check(int s, int t) {
    int l = t - s;
    for (int i = 2 * s; i < 2 * s + l; i++) {
        if (m[i] >= N || (0 <= m[i + l] && m[i + l] < N) ||
            (m[i] >= 0 && (m[i + l] >= 0 && m[i + l] != m[i] + N)) ||
            (m[i + l] >= 0 && (m[i] >= 0 && m[i + l] != m[i] + N))) {
            return false;
        }
    }
    return true;
}

bool solve() {
    memset(m, -1, sizeof(m));
    for (int i = 0; i < N; i++) {
        if (A[i] >= 0) {
            if (m[A[i]] >= 0) {
                return false;
            }
            m[A[i]] = i;
        }
        if (B[i] >= 0) {
            if (m[B[i]] >= 0) {
                return false;
            }
            m[B[i]] = i + N;
        }
    }

    dp[0] = true;
    for (int i = 0; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            dp[j] = dp[j] || (dp[i] && check(i, j));
        }
    }

    return dp[N];
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        if (A[i] > 0) {
            A[i]--;
        }
        if (B[i] > 0) {
            B[i]--;
        }
    }

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
