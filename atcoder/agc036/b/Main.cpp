/*
[agc036] B - Do Not Duplicate
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 2e5;
const int MAX_A = 2e5;
const int MAX_LOG_NK = 64;

int N;
ll K;
int A[MAX_N];
int rlast[MAX_A + 1];
bool has[MAX_A + 1];
ll d[MAX_LOG_NK][MAX_N];
vector<int> ans;

void solve() {
    for (int i = N - 1; i >= 0; i--) {
        rlast[A[i]] = N + i;
    }
    for (int i = N - 1; i >= 0; i--) {
        d[0][i] = rlast[A[i]] - i + 1;
        rlast[A[i]] = i;
    }

    for (int k = 1; k < MAX_LOG_NK; k++) {
        for (int i = 0; i < N; i++) {
            d[k][i] =
                min(N * K + 1, d[k - 1][i] + d[k - 1][(i + d[k - 1][i]) % N]);
        }
    }

    ll cur = 0;
    for (int k = MAX_LOG_NK - 1; k >= 0; k--) {
        ll nxt = cur + d[k][cur % N];
        if (nxt <= N * K) {
            cur = nxt;
        }
    }

    for (ll i = cur; i < N * K; i++) {
        int a = A[i % N];
        if (has[a]) {
            while (ans.back() != a) {
                has[ans.back()] = false;
                ans.pop_back();
            }
            has[a] = false;
            ans.pop_back();
        } else {
            ans.push_back(a);
            has[a] = true;
        }
    }
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    solve();

    for (int a : ans) {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}
