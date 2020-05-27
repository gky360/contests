/*
[abc142] B - Roller Coaster
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;

int N, K;
int h[MAX_N];

ll solve() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (h[i] >= K) {
            cnt++;
        }
    }

    return cnt;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    cout << solve() << endl;

    return 0;
}
