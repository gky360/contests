/*
[agc037] C - Numbers on a Circle
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;

int N;
int A[MAX_N], B[MAX_N];

ll solve() {
    priority_queue<pii> q;
    for (int i = 0; i < N; i++) {
        q.push({B[i], i});
    }

    ll ans = 0;
    while (!q.empty()) {
        pii p = q.top();
        q.pop();
        int i = p.second;
        int d = B[(i + N - 1) % N] + B[(i + 1) % N];
        int m = (B[i] - A[i]) / d;
        if (m > 0) {
            ans += m;
            B[i] -= m * d;
            if (B[i] > A[i]) {
                q.push({B[i], i});
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (B[i] != A[i]) {
            return -1;
        }
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    cout << solve() << endl;

    return 0;
}
