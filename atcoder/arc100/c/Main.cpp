// ARC100
// C - Linear Approximation

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 200000;

int N;
int B[MAX_N];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        B[i] = a - i + 1;
    }
    sort(B, B + N);

    int b = B[N / 2];
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += abs(B[i] - b);
    }
    cout << ans << endl;

    return 0;
}
