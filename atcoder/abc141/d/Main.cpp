/*
[abc141] D - Powerful Discount Tickets
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;

int N, M;
int A[MAX_N];

ll solve() {
    priority_queue<int> q;
    for (int i = 0; i < N; i++) {
        q.push(A[i]);
    }

    for (int i = 0; i < M; i++) {
        int a = q.top();
        q.pop();
        q.push(a / 2);
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += q.top();
        q.pop();
    }

    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
