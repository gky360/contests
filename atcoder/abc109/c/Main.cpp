// ARC109
// C - Skip

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 100000;

int N, X;
int x[MAX_N];

int gcd(int a, int b) {
    while (b > 0) {
        swap(b, a %= b);
    }
    return a;
}

int solve() {
    int ans = abs(x[0] - X);
    for (int i = 1; i < N; i++) {
        ans = gcd(ans, abs(x[i] - X));
    }
    return ans;
}

int main() {
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    cout << solve() << endl;

    return 0;
}
