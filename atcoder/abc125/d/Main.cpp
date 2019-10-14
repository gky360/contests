/*
[abc125] D - Flipping Signs
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;
const int MAX_A = 1e9;

int N;
int A[MAX_N];

ll solve() {
    ll s = 0;
    int m = MAX_A;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        s += abs(A[i]);
        m = min(m, abs(A[i]));
        if (A[i] <= 0) {
            cnt++;
        }
    }

    if (cnt % 2 == 0) {
        return s;
    }
    return s - 2 * m;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
