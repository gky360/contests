// TDPC
// J - ボール

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 16;
const double INF = 1e8;

int N;
double memo[1 << MAX_N];

double e(int x) {
    if (memo[x] < INF) {
        return memo[x];
    }
    for (int j = 1; j < MAX_N - 1; j++) {
        double a = 0.0;
        int c = 0;
        for (int i = j - 1; i <= j + 1; i++) {
            int b = 1 << i;
            if (x & b) {
                a += e(x - b);
                c++;
            }
        }
        if (c > 0) {
            memo[x] = min(memo[x], (a + 3.0) / c);
        }
    }

    return memo[x];
}

int main() {
    int x, xi;

    cin >> N;
    x = 0;
    for (int i = 0; i < N; i++) {
        cin >> xi;
        x = (x | (1 << xi));
    }

    fill(memo, memo + (1 << MAX_N), INF);
    memo[0] = 0.0;

    cout << setprecision(10) << fixed << e(x) << endl;

    return 0;
}
