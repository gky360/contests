// AGC021
// A - Digit Sum 2

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_K = 16;

ll N;
int d[MAX_K + 1];

int solve() {
    int seq_9 = -1;
    int K;
    for (ll i = 0, t = 1; i <= MAX_K; i++, t *= 10) {
        d[i] = N / t % 10;
        if (d[i] == 9 && seq_9 == i - 1) {
            seq_9 = i;
        }
        if (d[i] != 0) {
            K = i + 1;
        }
    }
    if (seq_9 >= K - 2) {
        return d[K - 1] + (K - 1) * 9;
    }
    return d[K - 1] - 1 + (K - 1) * 9;
}

int main() {
    cin >> N;

    cout << solve() << endl;

    return 0;
}
