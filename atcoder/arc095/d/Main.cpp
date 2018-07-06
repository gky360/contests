// ARC095
// D - Binomial Coefficients

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 100000;

int N;
int a[MAX_N];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a, a + N);

    if (N == 2) {
        cout << a[1] << " " << a[0] << endl;
        return 0;
    }

    int n = a[N - 1];
    int mid_idx = upper_bound(a, a + N - 1, n / 2) - a;
    int r = (a[mid_idx] - n / 2 > n / 2 - a[mid_idx - 1]) ? a[mid_idx - 1]
                                                          : a[mid_idx];
    cout << n << " " << r << endl;

    return 0;
}
