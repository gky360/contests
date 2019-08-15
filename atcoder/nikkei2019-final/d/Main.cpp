/*
[nikkei2019-final] D - Deforestation
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_M = 2e5;

int N, M;
int T[MAX_M], L[MAX_M], R[MAX_M];

ll solve() {
    pii es[MAX_M * 2];
    for (int i = 0; i < M; i++) {
        es[2 * i + 0] = {L[i] - 1, T[i]};
        es[2 * i + 1] = {R[i], -T[i]};
    }
    sort(es, es + 2 * M);

    ll ans = 0;
    multiset<int> s;
    int j = 0;
    for (int i = 0; i < N; i++) {
        for (; j < 2 * M && es[j].first <= i; j++) {
            if (es[j].second > 0) {
                s.insert(es[j].second);
            } else {
                s.erase(-es[j].second);
            }
        }
        if (!s.empty()) {
            ans += *s.rbegin();
        }
    }

    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> T[i] >> L[i] >> R[i];
    }

    cout << solve() << endl;

    return 0;
}
