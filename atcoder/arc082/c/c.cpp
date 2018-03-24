// ARC082
// C - Together

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 100000;
const int MAX_A = 100000;

int N;
int a[MAX_N];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a, a + N);

    int ans = 0;
    for (int i = 0; i < MAX_A; i++) {
        int cnt = upper_bound(a, a + N, i + 1) - lower_bound(a, a + N, i - 1);
        ans = max(ans, cnt);
    }

    cout << ans << endl;

    return 0;
}
