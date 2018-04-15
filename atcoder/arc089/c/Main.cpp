// ARC089
// C - Traveling

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 100000;

int N;
int t[MAX_N + 1], x[MAX_N + 1], y[MAX_N + 1];

bool solve() {
    for (int i = 1; i <= N; i++) {
        int mht = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
        int dt = t[i] - t[i - 1];
        if (!(mht <= dt && ((dt - mht) % 2 == 0))) {
            return false;
        }
    }

    return true;
}

int main() {
    cin >> N;
    t[0] = x[0] = y[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> t[i] >> x[i] >> y[i];
    }

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
