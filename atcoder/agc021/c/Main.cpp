// AGC021
// C - Tiling

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 1000, MAX_M = 1000;

int N, M, A, B;
char ans[MAX_N][MAX_M];

void fill_22(int n, int m, int a, int b) {
    for (int k = 0; k < a; k++) {
        int i = (k / 2) / (m / 2) * 2 + (k % 2);
        int j = (k / 2) % (m / 2) * 2;
        ans[i][j] = '<';
        ans[i][j + 1] = '>';
    }
    for (int k = 0; k < b; k++) {
        int i = ((a + 1) / 2 + k / 2) / (m / 2) * 2;
        int j = ((a + 1) / 2 + k / 2) % (m / 2) * 2 + (k % 2);
        ans[i][j] = '^';
        ans[i + 1][j] = 'v';
    }
}

bool solve() {
    if (2 * (A + B) > N * M) {
        return false;
    }
    memset(ans, '.', sizeof(ans));

    if (N % 2 == 0 && M % 2 == 0) {
        if (2 * (A + B) == N * M && (A % 2 == 1 || B % 2 == 1)) {
            return false;
        }
        fill_22(N, M, A, B);
    } else if (N % 2 != M % 2) {
        if (M % 2 == 1) {
            if ((A > (M - 1) * N / 2) ||
                (2 * (A + B) == N * M && (A % 2 == 1))) {
                return false;
            }
            fill_22(N, M - 1, A, max(0, B - N / 2));
            for (int i = 0; i < min(B, N / 2); i++) {
                ans[2 * i][M - 1] = '^';
                ans[2 * i + 1][M - 1] = 'v';
            }
        } else {
            if ((B > (N - 1) * M / 2) ||
                (2 * (A + B) == N * M && (B % 2 == 1))) {
                return false;
            }
            fill_22(N - 1, M, max(0, A - M / 2), B);
            for (int j = 0; j < min(A, M / 2); j++) {
                ans[N - 1][2 * j] = '<';
                ans[N - 1][2 * j + 1] = '>';
            }
        }
    } else {
        if (A > (M - 1) * N / 2 || B > (N - 1) * M / 2) {
            return false;
        }
        int a = A, b = B;
        bool is_33 =
            (2 * (A + B) == N * M - 1 && (B % 2 != ((N - 1) * M / 2) % 2));
        if (is_33) {
            if (a > 0) {
                a--;
                ans[N - 3][M - 3 + 0] = '<';
                ans[N - 3][M - 3 + 1] = '>';
            }
            if (a > 0) {
                a--;
                ans[N - 1][M - 3 + 1] = '<';
                ans[N - 1][M - 3 + 2] = '>';
            }
            if (b > 0) {
                b--;
                ans[N - 3 + 1][M - 3] = '^';
                ans[N - 3 + 2][M - 3] = 'v';
            }
            if (b > 0) {
                b--;
                ans[N - 3 + 0][M - 1] = '^';
                ans[N - 3 + 1][M - 1] = 'v';
            }
        }
        int rim_a_cnt = min(a, (M - (is_33 ? 3 : 1)) / 2);
        a -= rim_a_cnt;
        for (int j = 0; j < rim_a_cnt; j++) {
            ans[N - 1][2 * j] = '<';
            ans[N - 1][2 * j + 1] = '>';
        }
        int rim_b_cnt = min(b, (N - (is_33 ? 3 : 1)) / 2);
        b -= rim_b_cnt;
        for (int i = 0; i < rim_b_cnt; i++) {
            ans[2 * i][M - 1] = '^';
            ans[2 * i + 1][M - 1] = 'v';
        }
        fill_22(N - 1, M - 1, a, b);
    }

    return true;
}

int main() {
    cin >> N >> M >> A >> B;

    if (solve()) {
        cout << "YES" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << ans[i][j];
            }
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
