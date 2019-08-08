/*
[yahoo-procon2019-qual] E - Odd Subrectangles
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

typedef int Number;
typedef vector<Number> Array;
typedef vector<Array> Matrix;
const Number eps = 0;

int mat_rank(Matrix A) {
    const int n = A.size(), m = A[0].size();
    int r = 0;
    for (int i = 0; r < n && i < m; ++i) {
        int pivot = r;
        for (int j = r + 1; j < n; ++j) {
            if (A[j][i]) {
                pivot = j;
                break;
            }
        }
        swap(A[pivot], A[r]);
        if (A[r][i] <= eps) {
            continue;
        }
        for (int j = r + 1; j < n; ++j) {
            if (A[j][i]) {
                for (int k = i; k < m; ++k) {
                    A[j][k] ^= A[r][k];
                }
            }
        }
        ++r;
    }
    return r;
}

const ll MOD = 998244353;

int N, M;
Matrix a;

ll pow2(int n) {
    ll ret = 1;
    for (int i = 0; i < n; i++) {
        ret = (ret << 1) % MOD;
    }
    return ret;
}

ll solve() {
    int r = mat_rank(a);
    return (pow2(N + M - 1) + MOD - pow2(N + M - r - 1)) % MOD;
}

int main() {
    cin >> N >> M;

    a.resize(N);
    for (int i = 0; i < N; i++) {
        a[i].resize(M);
        for (int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
    cout << solve() << endl;

    return 0;
}
