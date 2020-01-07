/*
[abc132] B - Ordinary Number
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 20;

int N;
int p[MAX_N];

ll solve() {
    int ans = 0;
    for (int i = 1; i < N - 1; i++) {
        if ((p[i - 1] < p[i] && p[i] < p[i + 1]) ||
            (p[i - 1] > p[i] && p[i] > p[i + 1])) {
            ans++;
        }
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> p[i];
    }

    cout << solve() << endl;

    return 0;
}
