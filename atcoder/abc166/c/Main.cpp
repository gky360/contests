/*
[abc166] C - Peaks
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
int H[MAX_N];
vector<int> g[MAX_N];

ll solve() {
    int ans = 0;
    for (int i = 0; i < N; i++) {
        bool ok = true;
        for (int to : g[i]) {
            if (H[to] >= H[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans++;
        }
    }

    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
    }

    cout << solve() << endl;

    return 0;
}
