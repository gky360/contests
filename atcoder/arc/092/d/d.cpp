// ARC092
// D - Two Sequences

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int K = 28;

int N;
vector<int> a, b;

int main() {
    cin >> N;
    a.resize(N);
    b.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    int ans = 0;
    for (int k = 0; k <= K; k++) {
        vector<int> q(N);
        for (int i = 0; i < N; i++) {
            q[i] = b[i] & ((1 << (k + 1)) - 1);
        }
        sort(q.begin(), q.end());

        ll cnt = 0;
        for (int i = 0; i < N; i++) {
            int p = a[i] & ((1 << (k + 1)) - 1);
            cnt += lower_bound(q.begin(), q.end(), (4 << k) - p) -
                   lower_bound(q.begin(), q.end(), (3 << k) - p);
            cnt += lower_bound(q.begin(), q.end(), (2 << k) - p) -
                   lower_bound(q.begin(), q.end(), (1 << k) - p);
        }
        if (cnt % 2 == 1) {
            ans |= (1 << k);
        }
    }

    cout << ans << endl;

    return 0;
}
