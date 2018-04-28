// AGC020
// B - Ice Rink Game

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int K;
vector<int> a;

int main() {
    cin >> K;
    a.resize(K);
    for (int i = 0; i < K; i++) {
        cin >> a[i];
    }

    ll l = 2, r = 2;
    for (int i = K - 1; i >= 0; i--) {
        l = (l + a[i] - 1) / a[i] * a[i];
        r = r / a[i] * a[i] + a[i] - 1;
        if (l > r) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << l << " " << r << endl;

    return 0;
}
