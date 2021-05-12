/*
[arc104] B - DNA Sequence
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 5000;

int N;
string S;

ll solve() {
    int cnt[4][MAX_N + 1];
    cnt[0][0] = cnt[1][0] = cnt[2][0] = cnt[3][0] = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            cnt[j][i + 1] = cnt[j][i];
        }
        int n;
        switch (S[i]) {
            case 'A':
                n = 0;
                break;
            case 'T':
                n = 1;
                break;
            case 'C':
                n = 2;
                break;
            case 'G':
                n = 3;
                break;
        }
        cnt[n][i + 1]++;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (cnt[0][j] - cnt[0][i] == cnt[1][j] - cnt[1][i] &&
                cnt[2][j] - cnt[2][i] == cnt[3][j] - cnt[3][i]) {
                ans++;
            }
        }
    }

    return ans;
}

int main() {
    cin >> N >> S;

    cout << solve() << endl;

    return 0;
}
