/**
 * Matrix
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

typedef double Number;
typedef vector<Number> Array;
typedef vector<Array> Matrix;
const Number EPS = 1e-8;
const Number ZERO = 0.0;
const Number ONE = 1.0;

Matrix identity(int n) {
    Matrix A(n, Array(n, ZERO));
    for (int i = 0; i < n; i++) A[i][i] = ONE;
    return A;
}

Number inner_product(const Array &a, const Array &b) {
    Number ans = ZERO;
    for (int i = 0; i < (int)a.size(); i++) ans += a[i] * b[i];
    return ans;
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

Matrix pow(const Matrix &A, ll e) {
    Matrix AA = A;
    Matrix ans = identity(A.size());
    for (; e > 0; e >>= 1) {
        if (e & 1) ans = mul(ans, AA);
        AA = mul(AA, AA);
    }
    return ans;
}

Number det(Matrix A) {
    const int n = A.size();
    Number D = ONE;
    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int j = i + 1; j < n; j++) {
            if (abs(A[j][i]) > abs(A[pivot][i])) pivot = j;
        }
        swap(A[pivot], A[i]);
        D *= A[i][i] * (i != pivot ? -1 : 1);
        if (abs(A[i][i]) <= EPS) break;

        for (int j = i + 1; j < n; j++) {
            for (int k = n - 1; k >= i; k--) {
                A[j][k] -= A[i][k] * A[j][i] / A[i][i];
            }
        }
    }
    return D;
}

Number tr(const Matrix &A) {
    Number ans = ZERO;
    for (int i = 0; i < (int)A.size(); ++i) ans += A[i][i];
    return ans;
}

int mat_rank(Matrix A) {
    const int n = A.size(), m = A[0].size();
    int r = 0;
    for (int i = 0; r < n && i < m; i++) {
        int pivot = r;
        for (int j = r + 1; j < n; j++) {
            if (fabs(A[j][i]) > fabs(A[pivot][i])) pivot = j;
        }
        swap(A[pivot], A[r]);
        if (fabs(A[r][i]) <= EPS) continue;

        for (int k = m - 1; k >= i; k--) A[r][k] /= A[r][i];

        for (int j = r + 1; j < n; j++) {
            for (int k = m - 1; k >= i; k--) A[j][k] -= A[r][k] * A[j][i];
        }
        r++;
    }
    return r;
}

/**
 * ガウスの消去法
 */
Matrix regularize(Matrix A) {
    const int n = A.size(), m = A[0].size();
    int r = 0;
    for (int i = 0; r < n && i < m; i++) {
        int pivot = r;
        for (int j = r + 1; j < n; j++) {
            if (fabs(A[j][i]) > fabs(A[pivot][i])) pivot = j;
        }
        swap(A[pivot], A[r]);
        if (fabs(A[r][i]) <= EPS) continue;

        for (int k = m - 1; k >= i; k--) A[r][k] /= A[r][i];

        for (int j = 0; j < n; j++) {
            if (j == r) continue;
            for (int k = m - 1; k >= i; k--) A[j][k] -= A[r][k] * A[j][i];
        }
        r++;
    }
    return A;
}
