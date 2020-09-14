/*
[ddcc2020-final] B - Hawker on Graph
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

typedef pll Number;
typedef vector<Number> Array;
typedef vector<Array> Matrix;

const int MAX_N = 200;
const int MAX_M = MAX_N * (MAX_N - 1);
const ll INF = 1e18;
const pll ZERO = {-INF, -INF};
const pll ONE = {0, -INF};

pll pls(const pll &a, const pll &b) {
    return {max(a.first, b.first), max(a.second, b.second)};
}

pll mul(const pll &a, const pll &b) {
    if (a == ZERO || b == ZERO) return ZERO;
    return {a.first + b.first, max(a.second + b.first, b.second)};
}

Matrix identity(int n) {
    Matrix A(n, Array(n, ZERO));
    for (int i = 0; i < n; i++) {
        A[i][i] = ONE;
    }
    return A;
}

Matrix mul(const Matrix &A, const Matrix &B) {
    Matrix C(A.size(), Array(B[0].size(), ZERO));
    for (int i = 0; i < (int)C.size(); i++) {
        for (int j = 0; j < (int)C[i].size(); j++) {
            for (int k = 0; k < (int)A[i].size(); k++) {
                C[i][j] = pls(C[i][j], mul(A[i][k], B[k][j]));
            }
        }
    }
    return C;
}

Matrix mat_pow(const Matrix &A, ll e) {
    Matrix AA = A;
    Matrix ans = identity(A.size());
    for (; e > 0; e >>= 1) {
        if (e & 1) {
            ans = mul(ans, AA);
        }
        AA = mul(AA, AA);
    }
    return ans;
}

int N, M;
ll W;
int S, K;
int u[MAX_M], v[MAX_M], w[MAX_M];

ll solve() {
    Matrix X(N, Array(N, ZERO));

    for (int j = 0; j < M; j++) {
        X[u[j]][v[j]] = {w[j], 0};
    }

    X = mat_pow(X, K);

    ll ans = -1;
    for (int i = 0; i < N; i++) {
        ans = max(ans, max(X[S][i].first + W, X[S][i].second));
    }
    return ans;
}

int main() {
    cin >> N >> M >> W >> S >> K;
    S--;
    for (int j = 0; j < M; j++) {
        cin >> u[j] >> v[j] >> w[j];
        u[j]--, v[j]--;
    }

    cout << solve() << endl;

    return 0;
}
