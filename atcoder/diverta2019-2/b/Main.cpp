/*
[diverta2019-2] B - Picking Up
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 50;

int N;
int x[MAX_N], y[MAX_N];
map<pii, int> cnt;

ll solve() {
    int max_cnt = 0;
    pii max_p = {-1, -1};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                continue;
            }
            pii p = {x[i] - x[j], y[i] - y[j]};
            cnt[p]++;
            if (max_cnt < cnt[p]) {
                max_cnt = cnt[p];
                max_p = p;
            }
        }
    }

    return N - cnt[max_p];
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    cout << solve() << endl;

    return 0;
}
