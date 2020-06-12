/*
[abc144] B - 81
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int N;

bool solve() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            if (N == i * j) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    cin >> N;

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
