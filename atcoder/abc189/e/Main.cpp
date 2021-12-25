/*
[abc189] E - Rotate and Flip
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

typedef ll Number;
typedef vector<Number> Array;
typedef vector<Array> Matrix;
const Number EPS = 1e-8;
const Number ZERO = 0.0;
const Number ONE = 1.0;

const int MAX_N = 2e5;
const int MAX_M = 2e5;
const int MAX_Q = 2e5;

Matrix identity(int n) {
    Matrix A(n, Array(n, ZERO));
    for (int i = 0; i < n; i++) A[i][i] = ONE;
    return A;
}

Array mul(const Matrix &A, const Array &x) {
    Array y(A.size(), ZERO);
    for (int i = 0; i < (int)A.size(); i++) {
        for (int j = 0; j < (int)x.size(); j++) y[i] += A[i][j] * x[j];
    }
    return y;
}

Matrix mul(const Matrix &A, const Matrix &B) {
    Matrix C(A.size(), Array(B[0].size(), ZERO));
    for (int i = 0; i < (int)C.size(); i++) {
        for (int j = 0; j < (int)C[i].size(); j++) {
            for (int k = 0; k < (int)A[i].size(); k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

int N;
ll X[MAX_N], Y[MAX_N];
int M;
pair<int, ll> op[MAX_M];
int Q;
int A[MAX_Q], B[MAX_Q];
Matrix m[MAX_M + 1];

void solve() {
    m[0] = identity(3);
    REP(i, M) {
        if (op[i].first == 1) {
            m[i + 1] = mul({{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}}, m[i]);
        } else if (op[i].first == 2) {
            m[i + 1] = mul({{0, -1, 0}, {1, 0, 0}, {0, 0, 1}}, m[i]);
        } else if (op[i].first == 3) {
            ll p = op[i].second;
            m[i + 1] = mul({{-1, 0, 2 * p}, {0, 1, 0}, {0, 0, 1}}, m[i]);
        } else {
            ll p = op[i].second;
            m[i + 1] = mul({{1, 0, 0}, {0, -1, 2 * p}, {0, 0, 1}}, m[i]);
        }
    }

    REP(q, Q) {
        Array xy1 = mul(m[A[q]], {X[B[q]], Y[B[q]], 1});
        assert(xy1[2] == 1);
        cout << xy1[0] << " " << xy1[1] << endl;
    }
}

int main() {
    cin >> N;
    REP(i, N) cin >> X[i] >> Y[i];
    cin >> M;
    REP(i, M) {
        cin >> op[i].first;
        if (op[i].first >= 3) cin >> op[i].second;
    }
    cin >> Q;
    REP(i, Q) cin >> A[i] >> B[i], B[i]--;

    solve();

    return 0;
}
