/*
[nikkei2019-2-qual] D - Shortest Path on a Line
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_M = 1e5;

int N, M;
int L[MAX_M], R[MAX_M], C[MAX_M];

ll solve() {
    pii l[MAX_M];
    for (int i = 0; i < M; i++) {
        l[i] = pii(L[i], i);
    }
    sort(l, l + M);

    priority_queue<pli, vector<pli>, greater<pli>> q;
    q.push({0, -1});
    int li = 0;
    for (int i = 0; i < N - 1; i++) {
        pli t = q.top();
        for (; li < M && l[li].first <= i; li++) {
            q.push({t.first + C[l[li].second], l[li].second});
        }
        while (!q.empty() && (q.top().second == -1 || R[q.top().second] <= i)) {
            q.pop();
        }
        if (q.empty()) {
            return -1;
        }
    }

    ll ans = q.top().first;
    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> L[i] >> R[i] >> C[i];
        L[i]--, R[i]--;
    }

    cout << solve() << endl;

    return 0;
}
