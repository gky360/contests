/*
[abc152] C - Low Elements
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 2e5;

int N;
int P[MAX_N];

ll solve() {
    int ans = 0;
    int mi = N + 1;
    for (int i = 0; i < N; i++) {
        if (P[i] < mi) {
            ans++;
            mi = P[i];
        }
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    cout << solve() << endl;

    return 0;
}
