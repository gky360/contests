// AtCoder Regular Contest 075
// D - Widespread

#include <cstdio>
#include <algorithm>
#define MAX_N 100000
using namespace std;
typedef long long int ll;


int N;
ll A, B;
ll h[MAX_N];

bool can(ll k) {
    ll remain = k;
    for (int i = 0; i < N && remain >= 0; i++) {
        remain -= max((ll)0, h[i] - k * B + A - B - 1) / (A - B);
    }
    return (remain >= 0);
}

int main() {

    ll l, r, k;

    scanf("%d", &N);
    scanf("%lld%lld", &A, &B);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &h[i]);
    }

    l = 0;
    r = (ll)1e9;
    while (r - l > 1) {
        k = (r + l + 1) / 2;
        if (can(k)) {
            r = k;
        } else {
            l = k;
        }
    }

    printf("%lld\n", (r + l + 1) / 2);

    return 0;

}



