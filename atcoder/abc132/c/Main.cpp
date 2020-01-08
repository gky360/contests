/*
[abc132] C - Divide the Problems
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 1e5;

int N;
int d[MAX_N];

ll solve() {
    sort(d, d + N);
    return d[N / 2] - d[N / 2 - 1];
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> d[i];
    }

    cout << solve() << endl;

    return 0;
}
