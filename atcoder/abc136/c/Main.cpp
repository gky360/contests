/*
[abc136] C - Build Stairs
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;

int N;
int H[MAX_N];

ll solve() {
    for (int i = N - 1; i > 0; i--) {
        if (H[i - 1] - H[i] == 1) {
            H[i - 1]--;
        } else if (H[i - 1] > H[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
