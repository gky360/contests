// TDPC
// H - ナップザック

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int MAX_N = 100;
const int MAX_W = 10000;
const int MAX_C = 50;

struct Baggage {
    int w, v, c;
    bool operator<(Baggage &b) { return c < b.c; }
};

int N, W, C;
Baggage bgs[MAX_N];
int dp[MAX_W + 1][MAX_C + 1][MAX_C + 1];

int main() {
    int ans;

    cin >> N >> W >> C;
    for (int i = 0; i < N; i++) {
        cin >> bgs[i].w >> bgs[i].v >> bgs[i].c;
    }

    memset(dp, -1, sizeof(dp));
    sort(bgs, bgs + N);

    dp[0][0][0] = 0;
    ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = W - bgs[i].w; j >= 0; j--) {
            for (int k = C; k >= 0; k--) {
                for (int l = 0; l <= bgs[i].c; l++) {
                    int nk = (l == bgs[i].c ? k : k + 1);
                    if (dp[j][k][l] < 0 || nk > C) {
                        continue;
                    }
                    dp[j + bgs[i].w][nk][bgs[i].c] = max(
                        dp[j + bgs[i].w][nk][bgs[i].c], dp[j][k][l] + bgs[i].v);
                    ans = max(ans, dp[j + bgs[i].w][nk][bgs[i].c]);
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
