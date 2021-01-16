/*
[abc168] F - . (Single Dot)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1000;
const int K = 6 * MAX_N + 6;
const int INF = 1e9 + 7;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;
int A[MAX_N], B[MAX_N], C[MAX_N], D[MAX_N], E[MAX_N], F[MAX_N];
int m[K][K];
vector<ll> xs, ys;

void solve() {
    xs.push_back(0), xs.push_back(-INF), xs.push_back(INF);
    ys.push_back(0), ys.push_back(-INF), ys.push_back(INF);
    for (int i = 0; i < N; i++) {
        xs.push_back(A[i]);
        xs.push_back(B[i]);
        ys.push_back(C[i]);
    }
    for (int i = 0; i < M; i++) {
        xs.push_back(D[i]);
        ys.push_back(E[i]);
        ys.push_back(F[i]);
    }
    sort(ALL(xs));
    sort(ALL(ys));
    xs.erase(unique(ALL(xs)), xs.end());
    ys.erase(unique(ALL(ys)), ys.end());
    int xl = xs.size(), yl = ys.size();
    xs.resize(xl * 2);
    ys.resize(yl * 2);
    for (int i = xl - 1; i >= 0; i--) xs[i * 2 + 1] = xs[i * 2] = xs[i];
    for (int i = yl - 1; i >= 0; i--) ys[i * 2 + 1] = ys[i * 2] = ys[i];

    for (int i = 0; i < N; i++) {
        int a = lower_bound(ALL(xs), A[i]) - xs.begin(),
            b = lower_bound(ALL(xs), B[i]) - xs.begin(),
            c = lower_bound(ALL(ys), C[i]) - ys.begin();
        for (int x = a; x <= b; x++) {
            m[x][c] = -1;
        }
    }
    for (int i = 0; i < M; i++) {
        int d = lower_bound(ALL(xs), D[i]) - xs.begin(),
            e = lower_bound(ALL(ys), E[i]) - ys.begin(),
            f = lower_bound(ALL(ys), F[i]) - ys.begin();
        for (int y = e; y <= f; y++) {
            m[d][y] = -1;
        }
    }

    ll ans = 0;
    queue<pii> q;
    int xz = lower_bound(ALL(xs), 0) - xs.begin(),
        yz = lower_bound(ALL(ys), 0) - ys.begin();
    q.push(pii(xz, yz));
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (x == -1 || x == K || y == -1 || y == K) {
            cout << "INF" << endl;
            return;
        }
        if (m[x][y] != 0) continue;
        m[x][y] = 1;
        ans += abs(xs[x + 1] - xs[x]) * abs(ys[y + 1] - ys[y]);
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            q.push(pii(nx, ny));
        }
    }

    cout << ans << endl;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> D[i] >> E[i] >> F[i];
    }

    solve();

    return 0;
}
