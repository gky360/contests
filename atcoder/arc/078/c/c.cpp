// AtCoder Regular Contest 078
// C - Splitting Pile

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_N = 200000;
const ll INF = (ll)1e17;

int N;
ll a[MAX_N];

int main() {

    ll sum, tmp, ans;

    cin >> N;
    sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        sum += a[i];
    }

    tmp = a[0];
    ans = abs(tmp - (sum - tmp));
    for (int i = 1; i < N - 1; i++) {
        tmp += a[i];
        ans = min(ans, abs(tmp - (sum - tmp)));
    }

    cout << ans << endl;

    return 0;

}



