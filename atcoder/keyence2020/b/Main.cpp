/*
[keyence2020] B - Robot Arms
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 100000;
const int INF = 1e9 + 1;

int N;
int X[MAX_N], L[MAX_N];

ll solve() {
    pii s[MAX_N];
    for (int i = 0; i < N; i++) {
        s[i].first = X[i] + L[i];
        s[i].second = X[i] - L[i];
    }
    sort(s, s + N);

    int ans = 0;
    int r = -INF;
    for (int i = 0; i < N; i++) {
        if (s[i].second >= r) {
            ans++;
            r = s[i].first;
        }
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> X[i] >> L[i];
    }

    cout << solve() << endl;

    return 0;
}
