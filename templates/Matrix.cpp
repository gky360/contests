/*
 * Matrix
 */

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

typedef double Number;
typedef vector<Number> Array;
typedef vector<Array> Matrix;
const Number eps = 1e-8;

Matrix identity(int n) {
    Matrix A(n, Array(n));
    for (int i = 0; i < n; i++) {
        A[i][i] = 1;
    }
    return A;
}

Number inner_product(const Array &a, const Array &b) {
    Number ans = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        ans += a[i] * b[i];
    }
    return ans;
}

Array mul(const Matrix &A, const Array &x) {
    Array y(A.size());
    for (int i = 0; i < (int)A.size(); i++) {
        for (int j = 0; j < (int)x.size(); j++) {
            y[i] += A[i][j] * x[j];
        }
    }
    return y;
}

Matrix mul(const Matrix &A, const Matrix &B) {
    Matrix C(A.size(), Array(B[0].size()));
    for (int i = 0; i < (int)C.size(); i++) {
        for (int j = 0; j < (int)C[i].size(); j++) {
            for (int k = 0; k < (int)A[i].size(); k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

Matrix pow(const Matrix &A, int e) {
    Matrix AA = A;
    Matrix ans = identity(A.size());
    for (; e > 0; e /= 2) {
        if (e & 1) {
            ans = mul(ans, AA);
        }
        AA = mul(AA, AA);
    }
    return ans;
}

Number det(Matrix A) {
    const int n = A.size();
    Number D = 1;
    for (int i = 0; i < n; ++i) {
        int pivot = i;
        for (int j = i + 1; j < n; ++j) {
            if (abs(A[j][i]) > abs(A[pivot][i])) {
                pivot = j;
            }
        }
        swap(A[pivot], A[i]);
        D *= A[i][i] * (i != pivot ? -1 : 1);
        if (abs(A[i][i]) <= eps) {
            break;
        }
        for (int j = i + 1; j < n; ++j) {
            for (int k = n - 1; k >= i; --k) {
                A[j][k] -= A[i][k] * A[j][i] / A[i][i];
            }
        }
    }
    return D;
}

Number tr(const Matrix &A) {
    Number ans = 0;
    for (int i = 0; i < (int)A.size(); ++i) {
        ans += A[i][i];
    }
    return ans;
}

int rank(Matrix A) {
    const int n = A.size(), m = A[0].size();
    int r = 0;
    for (int i = 0; r < n && i < m; ++i) {
        int pivot = r;
        for (int j = r + 1; j < n; ++j) {
            if (fabs(A[j][i]) > fabs(A[pivot][i])) {
                pivot = j;
            }
        }
        swap(A[pivot], A[r]);
        if (fabs(A[r][i]) <= eps) {
            continue;
        }
        for (int k = m - 1; k >= i; --k) {
            A[r][k] /= A[r][i];
        }
        for (int j = r + 1; j < n; ++j) {
            for (int k = i; k < m; ++k) {
                A[j][k] -= A[r][k] * A[j][i];
            }
        }
        ++r;
    }
    return r;
}
