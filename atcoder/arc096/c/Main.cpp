// ARC096
// C - Half and Half

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int solve(int a, int b, int c, int x, int y) {
    c = min(a + b, 2 * c);
    a = min(a, c);
    b = min(b, c);
    int z = min(x, y);
    return (x - z) * a + (y - z) * b + z * c;
}

int main() {
    int A, B, C, X, Y;

    cin >> A >> B >> C >> X >> Y;

    cout << solve(A, B, C, X, Y) << endl;

    return 0;
}
