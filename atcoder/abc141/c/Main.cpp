/*
[abc141] C - Attack Survival
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;

int N, K, Q;
int A[MAX_N];
int cnt[MAX_N];

void solve() {
    for (int i = 0; i < Q; i++) {
        cnt[A[i]]++;
    }
    for (int i = 0; i < N; i++) {
        cout << (K - Q + cnt[i] > 0 ? "Yes" : "No") << endl;
    }
}

int main() {
    cin >> N >> K >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> A[i];
        A[i]--;
    }

    solve();

    return 0;
}
