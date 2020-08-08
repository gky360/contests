/*
[agc041] B - Voting Judges
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;
const int INF = 1e9 + 1;

int N;
ll M;
int V, P;
ll A[MAX_N + 1];
ll s[MAX_N + 1];

ll solve() {
    A[0] = INF;
    sort(A, A + N + 1, greater<int>());
    s[0] = 0;
    for (int i = 1; i <= N; i++) {
        s[i] = s[i - 1] + A[i];
    }

    for (int x = P + 1; x <= N; x++) {
        if (A[x] + M < A[P] ||
            (x - P) * (A[x] + M) - s[x - 1] + s[P - 1] + (P + N - x) * M <
                M * V) {
            return x - 1;
        }
    }

    return N;
}

int main() {
    cin >> N >> M >> V >> P;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
