// ARC084
// C - Snuke Festival

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int INF = 1e9 + 1;

int N;
vector<int> a[3];

int main() {
    cin >> N;
    for (int j = 0; j < 3; j++) {
        a[j].resize(N);
        for (int i = 0; i < N; i++) {
            cin >> a[j][i];
        }
        sort(a[j].begin(), a[j].end());
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        int u, l;
        u = lower_bound(a[0].begin(), a[0].end(), a[1][i]) - a[0].begin();
        l = a[2].end() - upper_bound(a[2].begin(), a[2].end(), a[1][i]);
        ans += 1LL * u * l;
    }

    cout << ans << endl;

    return 0;
}
