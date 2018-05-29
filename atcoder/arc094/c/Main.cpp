// ARC094
// C - Same Integers

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int a[3];

int main() {
    cin >> a[0] >> a[1] >> a[2];

    int max_a = *max_element(a, a + 3);
    int s = a[0] + a[1] + a[2];
    int ans = (3 * (max_a + (3 * max_a - s) % 2) - s) / 2;

    cout << ans << endl;

    return 0;
}
