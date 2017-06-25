// AtCoder Regular Contest 076
// C - Reconciled?

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

const ll MOD = 1000000007;

int N, M;

ll calc() {
    ll res;
    ll fact = 1;

    if (N < M) {
        swap(N, M);
    }
    if (N - M > 1) {
        return 0;
    }
    for (int i = 1; i <= M; i++) {
        fact *= i;
        fact %= MOD;
    }
    res = fact * fact % MOD;
    if (N == M) {
        res *= 2;
        res %= MOD;
    } else {
        res *= N;
        res %= MOD;
    }
    return res;
}

int main() {

    cin >> N >> M;
    cout << calc() << endl;

    return 0;

}



