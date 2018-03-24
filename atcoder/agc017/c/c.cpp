// AtCoder Grand Contest 017
// C - Snuke and Spells

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


const int MAX_N = 200000;
const int MAX_M = 200000;

int N, M;
int A[MAX_N];
int cnt[MAX_N + 1];
int sec_raw[2 * MAX_N + 2];
int *sec = sec_raw + MAX_N;

int main() {

    int x, y;
    int idx;
    int ans;

    cin >> N >> M;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        cnt[A[i]]++;
    }
    memset(sec_raw, 0, sizeof(sec_raw));
    for (int i = 1; i <= N; i++) {
        sec[i - cnt[i] + 1]++;
        sec[i + 1]--;
    }
    ans = 0;
    for (int i = -N + 1; i <= N; i++) {
        sec[i] += sec[i - 1];
        ans += (i >= 1 && sec[i] == 0 ? 1 : 0);
    }

    for (int q = 0; q < M; q++) {
        cin >> x >> y; x--;
        idx = A[x] - cnt[A[x]] + 1;
        sec[idx]--;
        ans += (idx >= 1 && sec[idx] == 0 ? 1 : 0);
        cnt[A[x]]--;
        A[x] = y;
        cnt[y]++;
        idx = y - cnt[y] + 1;
        ans -= (idx >= 1 && sec[idx] == 0 ? 1 : 0);
        sec[idx]++;

        cout << ans << endl;
    }

    return 0;

}



