/*
[abc167] D - Teleporter
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

int N;
ll K;
int A[MAX_N];

ll solve() {
    vector<int> visited(N, -1);
    int v = 0;
    REP(i, N + 1) {
        if (visited[v] != -1) {
            int c = visited[v];
            int t = K < c ? K : ((K - c) % (i - c) + c);
            return (find(ALL(visited), t) - visited.begin()) + 1;
        }
        visited[v] = i;
        v = A[v];
    }
    return -1;
}

int main() {
    cin >> N >> K;
    REP(i, N) {
        cin >> A[i];
        A[i]--;
    }

    cout << solve() << endl;

    return 0;
}
