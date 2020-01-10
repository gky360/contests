/**
 * BitMatrix
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_B = 60;

typedef bitset<MAX_B> Array;
typedef vector<Array> Matrix;

/**
 * ガウスの消去法
 */
Matrix regularize(Matrix A) {
    const int n = A.size(), m = A[0].size();
    int r = 0;
    for (int i = 0; r < n && i < m; i++) {
        int pivot = r;
        for (int j = r; j < n; j++) {
            if (A[j][m - i - 1]) {
                pivot = j;
                break;
            }
        }
        swap(A[pivot], A[r]);
        if (!A[r][m - i - 1]) {
            continue;
        }
        for (int j = 0; j < n; j++) {
            if (j != r && A[j][m - i - 1]) {
                A[j] ^= A[r];
            }
        }
        r++;
    }
    return A;
}
