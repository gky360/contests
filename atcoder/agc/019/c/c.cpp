// AtCoder Grand Contest 019
// C - Fountain Walk

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


const int MAX_N = 200000;
const int INF = (int)1e9;
const long double PI_L = acos(-1.0L);

int X1, Y1, X2, Y2;
int N, K;
int inv_x, inv_y;
vector<pii> a;
int dp[MAX_N];

int main() {

    int x, y;
    long double ans;
    int cnt, arcs;

    cin >> X1 >> Y1 >> X2 >> Y2;
    cin >> N;
    inv_x = X1 > X2 ? -1 : 1;
    inv_y = Y1 > Y2 ? -1 : 1;
    X1 *= inv_x; X2 *= inv_x;
    Y1 *= inv_y; Y2 *= inv_y;

    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        x *= inv_x; y *= inv_y;
        if (X1 <= x && x <= X2 && Y1 <= y && y <= Y2) {
            a.push_back(pii(x, y));
        }
    }
    sort(a.begin(), a.end());
    K = a.size();

    fill(dp, dp + K, INF);
    for (int j = 0; j < K; j++) {
        *lower_bound(dp, dp + K, a[j].second) = a[j].second;
    }
    cnt = lower_bound(dp, dp + K, INF) - dp;
    arcs = (cnt == min(X2 - X1, Y2 - Y1) + 1) ? cnt + 1 : cnt;

    ans = 100.0L * ((X2 - X1) + (Y2 - Y1)) - 20.0L * cnt + 5.0L * arcs * PI_L;

    cout << fixed << setprecision(20) << ans << endl;

    return 0;

}

