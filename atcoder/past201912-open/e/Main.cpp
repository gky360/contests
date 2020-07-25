/*
[past201912-open] E - SNS のログ / Restore
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 100;
const int MAX_Q = 500;

int N, Q;
int op[MAX_Q], a[MAX_Q], b[MAX_Q];
bool f[MAX_N][MAX_N];

void solve() {
    for (int q = 0; q < Q; q++) {
        switch (op[q]) {
            case 1:
                f[a[q]][b[q]] = true;
                break;
            case 2:
                for (int i = 0; i < N; i++) {
                    if (f[i][a[q]]) {
                        f[a[q]][i] = true;
                    }
                }
                break;
            case 3:
                vector<int> fs;
                for (int i = 0; i < N; i++) {
                    if (f[a[q]][i]) {
                        fs.push_back(i);
                    }
                }
                for (int i : fs) {
                    for (int j = 0; j < N; j++) {
                        if (j != a[q] && f[i][j]) {
                            f[a[q]][j] = true;
                        }
                    }
                }
                break;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (f[i][j] ? 'Y' : 'N');
        }
        cout << endl;
    }
}

int main() {
    cin >> N >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> op[i];
        if (op[i] == 1) {
            cin >> a[i] >> b[i];
            a[i]--, b[i]--;
        } else {
            cin >> a[i];
            a[i]--;
        }
    }

    solve();

    return 0;
}
