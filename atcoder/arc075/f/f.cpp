// AtCoder Regular Contest 075
// F - Mirrored

#include <cstdio>
#include <cmath>
using namespace std;
typedef long long int ll;


const int MAX_K = 9;

ll D;
ll pow_dec[2 * MAX_K + 1];
ll ans;

ll count_n(int l, int r, ll d) {
    if (l - r < 0) {
        return (d == 0) ? 1 : 0;
    }

    ll cnt = 0;
    int k;
    for (int i = (d / pow_dec[r] % 10 + 10) % 10; i > -10; i -= 10) {
        if (r == 0 && i > 0) {
            continue;
        }
        k = 10 - abs(i);
        if (r == 0 && -i >= 0) {
            k--;
        }
        cnt += k * count_n(l - 1, r + 1, d + i * pow_dec[l] - i * pow_dec[r]);
    }

    return cnt;
}

int main() {

    pow_dec[0] = 1;
    for (int i = 1; i <= 2 * MAX_K; i++) {
        pow_dec[i] = pow_dec[i - 1] * 10;
    }

    scanf("%lld", &D);

    ans = 0;
    for (int i = 0; i <= 2 * MAX_K; i++) {
        ans += count_n(i, 0, D);
    }

    printf("%lld\n", ans);

    return 0;

}
