/*
[nikkei2019-2-qual] C - Swaps
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;

int N;
pii BA[MAX_N];

bool solve() {
    sort(BA, BA + N);
    pii ax[MAX_N];

    for (int i = 0; i < N; i++) {
        ax[i].first = BA[i].second;
        ax[i].second = i;
    }
    sort(ax, ax + N);

    for (int i = 0; i < N; i++) {
        if (ax[i].first > BA[i].first) {
            return false;
        }
    }

    vector<bool> visited(N);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        cnt++;

        int v = i;
        while (!visited[v]) {
            visited[v] = true;
            v = ax[v].second;
        }
    }
    if (cnt > 1) {
        return true;
    }

    for (int i = 0; i < N - 1; i++) {
        if (ax[i + 1].first <= BA[i].first) {
            return true;
        }
    }

    return false;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> BA[i].second;
    }
    for (int i = 0; i < N; i++) {
        cin >> BA[i].first;
    }

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
