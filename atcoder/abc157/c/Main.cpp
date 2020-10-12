/*
[abc157] C - Guess The Number
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_M = 5;

int N, M;
int s[MAX_M], c[MAX_M];

int digit(int n, int k) {
    for (int i = 0; i < k; i++) {
        n /= 10;
    }
    return n % 10;
}

bool can(int n) {
    for (int i = 0; i < M; i++) {
        if (digit(n, N - s[i]) != c[i]) return false;
    }
    return true;
}

ll solve() {
    int n = 1;
    for (int i = 1; i < N; i++) {
        n *= 10;
    }
    for (int i = N == 1 ? 0 : n; i < n * 10; i++) {
        if (can(i)) return i;
    }
    return -1;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> s[i] >> c[i];
    }

    cout << solve() << endl;

    return 0;
}
