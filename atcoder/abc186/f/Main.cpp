/*
[abc186] F - Rook on Grid
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double DD;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(c) (c).begin(), (c).end()

const int MAX_W = 2e5;
const int MAX_M = 2e5;

template <typename T>
class BIT {
public:
    vector<T> b;
    BIT(int n) : b(n + 1) {}
    T sum(int i) {  // i : [0, n], returns sum of [0, i)
        T s = 0;
        for (; i > 0; i -= i & -i) s += b[i];
        return s;
    }
    void add(int i, T x) {  // i : [0, n)
        for (i += 1; i < (int)b.size(); i += i & -i) b[i] += x;
    }
};

int H, W, M;
pii XY[MAX_M];
bool visited[MAX_W];

ll solve() {
    sort(XY, XY + M);

    int r = W;
    if (M > 0 && XY[0].first == 0) r = XY[0].second;

    ll ans = 0;
    REP(i, M) {
        if (!visited[XY[i].second] && XY[i].second < r) {
            ans += XY[i].first;
            visited[XY[i].second] = true;
        }
    }
    REP(i, r) if (!visited[i]) ans += H;

    BIT<int> bit(W);
    int m = 0;
    REP(i, H) {
        if (m < M && XY[m].second == 0) break;
        int x = (m < M && XY[m].first == i) ? XY[m].second : W;
        ans += bit.sum(x);
        if (i == 0) {
            if (m < M && XY[m].first == 0) {
                for (int j = XY[m].second; j < W; j++) bit.add(j, 1);
            }
        }
        for (; m < M && XY[m].first == i; m++) {
            int w = XY[m].second;
            if (bit.sum(w + 1) - bit.sum(w) == 0) bit.add(w, 1);
        }
    }

    return ans;
}

int main() {
    cin >> H >> W >> M;
    REP(i, M) cin >> XY[i].first >> XY[i].second, XY[i].first--, XY[i].second--;

    cout << solve() << endl;

    return 0;
}
