// AtCoder Grand Contest 010
// B - Boxes

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_N = 100000;

int N;
ll a[MAX_N];

bool can() {
    ll sum_a, sum_n;
    ll k, k_a, d;

    sum_a = 0;
    for (int i = 0; i < N; i++) {
        sum_a += a[i];
    }
    sum_n = ((ll)N + 1) * N / 2;
    if (sum_a % sum_n != 0) {
        return false;
    }
    k = sum_a / sum_n;

    k_a = 0;
    for (int i = 0; i < N; i++) {
        d = k - (a[(i + 1) % N] - a[i]);
        if (d < 0 || d % N != 0) {
            return false;
        }
        k_a += d / N;
    }

    return (k == k_a);
}

int main() {

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << (can() ? "YES" : "NO") << endl;

    return 0;

}

