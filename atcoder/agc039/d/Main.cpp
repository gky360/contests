/*
[agc039] D - Incenters
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

typedef complex<double> P;

const int MAX_N = 3000;
const P I = 1.0i;

int N, L;
int T[MAX_N];

P solve() {
    P ans;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double theta = M_PI * (T[i] + T[j]) / L;
            ans += exp(I * theta) * (double)(N + 2 * i - 2 * j);
        }
    }

    ans *= 6.0 / N / (N - 1) / (N - 2);

    return ans;
}

int main() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }

    P ans = solve();
    cout << setprecision(15) << real(ans) << " " << imag(ans) << endl;

    return 0;
}
