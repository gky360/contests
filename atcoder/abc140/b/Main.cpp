/*
[abc140] B - Buffet
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 20;

int N;
int A[MAX_N], B[MAX_N], C[MAX_N - 1];

ll solve() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += B[A[i]];
        if (i < N - 1 && A[i + 1] == A[i] + 1) {
            ans += C[A[i]];
        }
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < N - 1; i++) {
        cin >> C[i];
    }

    cout << solve() << endl;

    return 0;
}
