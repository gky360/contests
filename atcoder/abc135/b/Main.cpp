/*
[abc135] B - 0 or 1 Swap
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 50;

int N;
int p[MAX_N];

bool check() {
    for (int i = 1; i < N; i++) {
        if (p[i - 1] > p[i]) {
            return false;
        }
    }
    return true;
}

bool solve() {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            swap(p[i], p[j]);

            if (check()) {
                return true;
            }

            swap(p[i], p[j]);
        }
    }

    return check();
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    cout << (solve() ? "YES" : "NO") << endl;

    return 0;
}
