/*
[abc145] C - Average Length
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 8;

int N;
int x[MAX_N], y[MAX_N];

double solve() {
    double s = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            s += sqrt((x[i] - x[j]) * (x[i] - x[j]) +
                      (y[i] - y[j]) * (y[i] - y[j]));
        }
    }

    double ans = s * 2 / N;
    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    cout << fixed << setprecision(10) << solve() << endl;

    return 0;
}
