/*
[abc182] B - Almost GCD
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 100;
const int MAX_A = 1000;

int N;
int A[MAX_N];
int cnt[MAX_A + 1];

ll solve() {
    for (int j = 2; j <= MAX_A; j++) REP(i, N) {
            if (A[i] % j == 0) cnt[j]++;
        }

    ll ans = max_element(cnt, cnt + MAX_A) - cnt;
    return ans;
}

int main() {
    cin >> N;
    REP(i, N) cin >> A[i];

    cout << solve() << endl;

    return 0;
}
