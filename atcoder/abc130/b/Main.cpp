/*
[abc130] B - Bounding
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 100;

int N, X;
int L[MAX_N + 1];

ll solve() {
    int d = 0;
    int ans = 0;
    for (int i = 0; i <= N && d <= X; i++) {
        ans++;
        d += L[i];
    }
    return ans;
}

int main() {
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> L[i];
    }

    cout << solve() << endl;

    return 0;
}
