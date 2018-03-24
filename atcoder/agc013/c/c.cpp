// AtCoder Grand Contest 013
// C - Ants on a Circle

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_N = 100000;

int N;
ll L, T;
ll x[MAX_N], xa[MAX_N];
int w[MAX_N];

int main() {

    ll d, k;
    int slide;

    cin >> N >> L >> T;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> w[i];
        w[i] = (w[i] == 1 ? 1 : -1);
        xa[i] = ((x[i] + w[i] * T) % L + L) % L;
    }
    sort(xa, xa + N);

    k = 0;
    for (int i = 1; i < N; i++) {
        d = (x[i] + w[i] * T) - (x[0] + w[0] * T);
        k += (d > 0) ? (d / L) : (-d / L + 1);
    }
    k = (k * w[0] + N) % N;
    slide = lower_bound(xa, xa + N, ((x[0] + w[0] * T) % L + L) % L) - xa;
    if (xa[slide] == xa[(slide + 1) % N] && w[0] > 0) {
        slide++;
    }

    for (int i = 0; i < N; i++) {
        cout << xa[(N + slide - k + i) % N] << endl;
    }

    return 0;

}

