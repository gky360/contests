/*
[abc151] B - Achieve the Goal
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 100;

int N, K, M;
int A[MAX_N];

ll solve() {
    int s = 0;
    for (int i = 0; i < N - 1; i++) {
        s += A[i];
    }

    int ans = max(0, N * M - s);
    if (ans > K) {
        return -1;
    }
    return ans;
}

int main() {
    cin >> N >> K >> M;
    for (int i = 0; i < N - 1; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
