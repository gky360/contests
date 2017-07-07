// AtCoder Regular Contest 077
// E - guruguru

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;


const int MAX_N = 100000;
const int MAX_M = 100000;
int N, M;
int a[MAX_N];
int imos0[2 * MAX_M + 1];
ll imos1[2 * MAX_M + 1];

int main() {

    int from, to;
    ll total, sum, ans;

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }

    memset(imos0, 0, sizeof(0));
    memset(imos1, 0, sizeof(0));
    total = 0;
    for (int i = 1; i < N; i++) {
        from = a[i - 1];
        to = a[i];
        if (from > to) {
            to += M;
        }
        total += to - from;
        imos0[from + 1]++;
        imos0[to + 1]--;
        imos1[from + 1] += from;
        imos1[to + 1] -= from;
    }
    for (int i = 0; i < 2 * M; i++) {
        imos0[i + 1] += imos0[i];
        imos1[i + 1] += imos1[i];
    }

    ans = total;
    for (int i = 0; i < M; i++) {
        sum = total;
        for (int j = i; j < 2 * M; j += M) {
            sum -= (ll)j * imos0[j] - imos1[j] - imos0[j];
        }
        ans = min(ans, sum);
    }

    cout << ans << endl;

    return 0;

}



