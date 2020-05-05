/*
[jsc2019-qual] D - Classified
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

int N;

void solve() {
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int d = 0;
            while (((i >> d) & 1) == ((j >> d) & 1)) {
                d++;
            }
            cout << d + 1 << " ";
        }
        cout << endl;
    }
}

int main() {
    cin >> N;

    solve();

    return 0;
}
