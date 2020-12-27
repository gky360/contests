/*
[abc166] B - Trick or Treat
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 100;
const int MAX_K = 100;

int N, K;
int cnt[MAX_N];

ll solve() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (cnt[i] == 0) ans++;
    }

    return ans;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int d;
        cin >> d;
        for (int j = 0; j < d; j++) {
            int a;
            cin >> a;
            a--;
            cnt[a]++;
        }
    }

    cout << solve() << endl;

    return 0;
}
