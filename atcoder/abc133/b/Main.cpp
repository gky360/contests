/*
[abc133] B - Good Distance
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 10;
const int MAX_D = 10;

int N, D;
int x[MAX_N][MAX_D];

bool is_ok(int p, int q) {
    int dist = 0;
    for (int d = 0; d < D; d++) {
        dist += (x[p][d] - x[q][d]) * (x[p][d] - x[q][d]);
    }
    int n = 0;
    while (n * n < dist) {
        n++;
    }
    return n * n == dist;
}

ll solve() {
    int ans = 0;
    for (int p = 0; p < N; p++) {
        for (int q = p + 1; q < N; q++) {
            if (is_ok(p, q)) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < D; j++) {
            cin >> x[i][j];
        }
    }

    cout << solve() << endl;

    return 0;
}
