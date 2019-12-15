/*
[abc129] F - Takahashi's Basics in Education and Learning
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

ll L, A, B;
int MOD;

class gf {
public:
    int n;
    gf() : n(0) {}
    gf(int n) : n(n % MOD) {}
    gf operator+(const gf x) const { return gf((n + x.n) % MOD); }
    gf operator*(const gf x) const { return gf((1LL * n * x.n) % MOD); }
    gf &operator+=(const gf x) { return *this = (*this + x); }
    gf &operator*=(const gf x) { return *this = (*this * x); }
};

typedef gf Number;
typedef vector<Number> Array;
typedef vector<Array> Matrix;

Matrix identity(int n) {
    Matrix A(n, Array(n));
    for (int i = 0; i < n; i++) {
        A[i][i] = 1;
    }
    return A;
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

Matrix pow(const Matrix &A, ll e) {
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

const Number eps = 1e-8;
const int D = 18;
ll c[D + 1];

ll solve() {
    for (ll d = 1, dec = 10; d <= D; d++, dec *= 10) {
        c[d] = min(L, max(dec - A + B - 1, 0LL) / B);
    }

    Array v = {0, (int)(A % (ll)MOD), 1};
    gf dec = 10;
    for (int d = 1; d <= D; d++) {
        Matrix A = {{dec, 1, 0}, {0, 1, (int)(B % (ll)MOD)}, {0, 0, 1}};
        v = mul(pow(A, c[d] - c[d - 1]), v);
        dec *= 10;
    }
    gf ans = v[0];

    return ans.n;
}

int main() {
    cin >> L >> A >> B >> MOD;

    cout << solve() << endl;

    return 0;
}
