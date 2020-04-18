/*
[abc139] F - Engines
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

typedef complex<double> P;

const int MAX_N = 100;

int N;
pair<double, P> ps[MAX_N];

namespace std {
bool operator<(const P& a, const P& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
}
}  // namespace std

double solve() {
    for (int i = 0; i < N; i++) {
        ps[i].first = arg(ps[i].second);
    }
    sort(ps, ps + N);

    double ans = 0;
    for (int i = 0; i < N; i++) {
        P s;
        for (int j = 0; j < N; j++) {
            s += ps[(i + j) % N].second;
            ans = max(ans, abs(s));
        }
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;
        ps[i].second = {x, y};
    }

    cout << setprecision(16) << solve() << endl;

    return 0;
}
