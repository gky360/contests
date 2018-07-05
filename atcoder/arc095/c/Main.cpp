// ARC095
// C - Many Medians

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 200000;

int N;
int x[MAX_N], y[MAX_N];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i];
        y[i] = x[i];
    }
    sort(y, y + N);

    for (int i = 0; i < N; i++) {
        int idx = (lower_bound(y, y + N, x[i]) - y < N / 2) ? N / 2 : N / 2 - 1;
        cout << y[idx] << endl;
    }

    return 0;
}
