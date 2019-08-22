/*
[abc119] C - Synthetic Kadomatsu
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

const int MAX_N = 8;
const int K = 3;
const int INF = 1e7;

int N;
int A[K];
int l[MAX_N];

ll solve() {
    int ans = INF;
    for (int pat = 0; pat < (1 << (2 * N)); pat++) {
        int cnt[K + 1];
        int s[K + 1];
        memset(cnt, 0, sizeof(cnt));
        memset(s, 0, sizeof(s));
        for (int i = 0; i < N; i++) {
            int n = (pat >> (i * 2)) & 0b11;
            cnt[n]++;
            s[n] += l[i];
        }

        int t = 0;
        for (int i = 0; i < K; i++) {
            t += (cnt[i] == 0) ? INF : (abs(s[i] - A[i]) + (cnt[i] - 1) * 10);
        }
        ans = min(ans, t);
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < K; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> l[i];
    }

    cout << solve() << endl;

    return 0;
}
