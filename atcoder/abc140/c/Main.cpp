/*
[abc140] C - Maximal Value
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 100;

int N;
int B[MAX_N - 1];

ll solve() {
    int ans = 0;
    for (int i = 1; i < N - 1; i++) {
        ans += min(B[i - 1], B[i]);
    }
    ans += B[0] + B[N - 2];

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        cin >> B[i];
    }

    cout << solve() << endl;

    return 0;
}
