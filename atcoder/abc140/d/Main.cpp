/*
[abc140] D - Face Produces Unhappiness
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int N, K;
string S;

ll solve() {
    int cnt = 0;
    for (int i = 1; i < N; i++) {
        if (S[i - 1] == S[i]) {
            cnt++;
        }
    }
    int ans = min(N - 1, cnt + 2 * K);

    return ans;
}

int main() {
    cin >> N >> K;
    cin >> S;

    cout << solve() << endl;

    return 0;
}
