/*
[past201912-open] D - 重複検査 / Duplicated?
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 200000;

int N;
int A[MAX_N];
int cnt[MAX_N];

void solve() {
    for (int i = 0; i < N; i++) {
        cnt[A[i]]++;
    }

    int src = find(cnt, cnt + N, 0) - cnt;
    if (src == N) {
        cout << "Correct" << endl;
        return;
    }
    int dst = find(cnt, cnt + N, 2) - cnt;

    cout << dst + 1 << " " << src + 1 << endl;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }

    solve();

    return 0;
}
