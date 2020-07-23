/*
[past201912-open] C - 3 番目 / The Third
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int N = 6;

int A[N];

ll solve() {
    sort(A, A + N);

    return A[N - 3];
}

int main() {
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
