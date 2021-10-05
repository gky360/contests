/*
[past202012-open] J - Long Long String
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

const int MAX_N = 2e5;
const ll MAX_X = 1e15;

string S;
ll X;
int N;
ll l[MAX_N + 1];

char solve() {
    N = S.length();
    l[0] = 0;
    REP(i, N)
    l[i + 1] = min(
        MAX_X, l[i] + ('a' <= S[i] && S[i] <= 'z' ? 1 : l[i] * (S[i] - '0')));

    for (int i = N; i >= 0; i--) {
        if (l[i] < X) {
            if ('a' <= S[i] && S[i] <= 'z') return S[i];
            X = (X - 1) % l[i] + 1;
        }
    }
    assert(false);
}

int main() {
    cin >> S;
    cin >> X;

    cout << solve() << endl;

    return 0;
}
