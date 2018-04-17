// ARC089
// D - Checker

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_K = 1000;

int N, K;
int m[2 * MAX_K + 1][2 * MAX_K + 1];

void mask(int x, int y) {
    int xl = x, xr = x + K;
    int yl = y, yr = y + K;
    xl %= 2 * K;
    xr %= 2 * K;
    yl %= 2 * K;
    yr %= 2 * K;
    m[xl][yl]++;
    m[xr][yl]--;
    m[xl][yr]--;
    m[xr][yr]++;
    if (xr < xl) {
        m[0][yl]++;
        m[0][yr]--;
    }
    if (yr < yl) {
        m[xl][0]++;
        m[xr][0]--;
    }
    if (xr < xl && yr < yl) {
        m[0][0]++;
    }
}

int main() {
    cin >> N >> K;

    memset(m, 0, sizeof(m));
    for (int i = 0; i < N; i++) {
        int x, y;
        char c;
        cin >> x >> y >> c;
        if (c == 'B') {
            mask(x, y);
            mask(x + K, y + K);
        } else {
            mask(x + K, y);
            mask(x, y + K);
        }
    }

    for (int j = 0; j < 2 * K; j++) {
        for (int i = 1; i < 2 * K; i++) {
            m[i][j] += m[i - 1][j];
        }
    }
    for (int i = 0; i < 2 * K; i++) {
        for (int j = 1; j < 2 * K; j++) {
            m[i][j] += m[i][j - 1];
        }
    }

    int ans = 0;
    for (int i = 0; i < 2 * K; i++) {
        ans = max(ans, *max_element(m[i], m[i] + 2 * K));
    }

    cout << ans << endl;

    return 0;
}
