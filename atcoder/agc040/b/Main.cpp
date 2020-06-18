/*
[agc040] B - Two Contests
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;

int N;
pii P[MAX_N];

ll solve() {
    sort(P, P + N);

    int mr[MAX_N];
    int mri = N - 1;
    mr[N - 1] = P[N - 1].second;
    for (int i = N - 2; i >= 0; i--) {
        if (P[i].second <= mr[i + 1]) {
            mr[i] = P[i].second;
            mri = i;
        } else {
            mr[i] = mr[i + 1];
        }
    }
    int min_r = mr[0], max_l = P[N - 1].first;

    int ans = 0;
    for (int i = 0; i < N - 1; i++) {
        if (i == mri) continue;
        ans = max(ans, max(0, min_r - max_l + 1) +
                           max(0, P[i].second - P[i].first + 1));
    }

    if (mri != N - 1) {
        for (int i = 0; i < N - 1; i++) {
            ans = max(ans, max(0, mr[i + 1] - max_l + 1) +
                               max(0, min_r - P[i].first + 1));
        }
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i].first >> P[i].second;
    }

    cout << solve() << endl;

    return 0;
}
