/*
[abc120] C - Unification
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;

int N;
string S;

ll solve() {
    int cnt[2];
    cnt[0] = cnt[1] = 0;
    for (int i = 0; i < N; i++) {
        cnt[S[i] - '0']++;
    }

    return min(cnt[0], cnt[1]) * 2;
}

int main() {
    cin >> S;
    N = S.size();

    cout << solve() << endl;

    return 0;
}
