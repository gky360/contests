/*
[abc137] D - Summer Vacation
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;

int N, M;
pii AB[MAX_N];
priority_queue<int> q;

ll solve() {
    sort(AB, AB + N);

    int ans = 0;
    for (int j = M - 1, i = 0; j >= 0; j--) {
        for (; i < N && AB[i].first <= M - j; i++) {
            q.push(AB[i].second);
        }
        if (!q.empty()) {
            ans += q.top();
            q.pop();
        }
    }

    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> AB[i].first >> AB[i].second;
    }

    cout << solve() << endl;

    return 0;
}
