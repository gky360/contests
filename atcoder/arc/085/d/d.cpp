// ARC085
// D - ABS

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int N, Z, W;
int a[2];

int main() {
    cin >> N >> Z >> W;
    for (int i = 0; i < N; i++) {
        cin >> a[i % 2];
    }

    if (N == 1) {
        cout << abs(a[0] - W) << endl;
        return 0;
    }

    cout << max(abs(a[(N - 1) % 2] - W), abs(a[(N - 1) % 2] - a[(N - 2) % 2]))
         << endl;

    return 0;
}
