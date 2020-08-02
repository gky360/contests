/*
[past201912-open] M - おまかせ / Auto Choice
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1000;
const int MAX_M = 100;
const double INF = 1e10;
const double EPS = 1e-10;

int N, M;
pii AB[MAX_N];
pii CD[MAX_M];

bool can(double st) {
    auto comp = [=](pii p0, pii p1) {
        return p0.second - st * p0.first > p1.second - st * p1.first;
    };
    sort(AB, AB + N, comp);
    sort(CD, CD + M, comp);

    int x = 0, y = 0;
    for (int i = 0; i < 4; i++) {
        x += AB[i].first;
        y += AB[i].second;
    }

    return (y + AB[4].second - st * (x + AB[4].first) >= 0) ||
           (y + CD[0].second - st * (x + CD[0].first) >= 0);
}

double solve() {
    double ok = 0, ng = INF;
    while (ng - ok > EPS) {
        double m = (ng + ok) / 2;
        if (can(m)) {
            ok = m;
        } else {
            ng = m;
        }
    }

    return ok;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> AB[i].first >> AB[i].second;
    }
    for (int i = 0; i < M; i++) {
        cin >> CD[i].first >> CD[i].second;
    }

    cout << setprecision(16) << solve() << endl;

    return 0;
}
