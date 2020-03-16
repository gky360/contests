/*
[abc135] E - Golf
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;

int K;
int X, Y;
vector<pii> ans;

bool solve() {
    int xs = 1, ys = 1;
    if (X < 0) {
        X = -X;
        xs = -1;
    }
    if (Y < 0) {
        Y = -Y;
        ys = -1;
    }
    bool swapped = false;
    if (X < Y) {
        swap(X, Y);
        swapped = true;
    }

    if (K % 2 == 0 && (X + Y) % 2 == 1) {
        return false;
    }

    if (X + Y < K && (X + Y) % 2 == 1) {
        ans.push_back({X, -K + X});
        ans.push_back({(K + 3 * X - Y) / 2, (-K + X + Y) / 2});
        ans.push_back({X, Y});
    } else if (X + Y == K) {
        ans.push_back({X, Y});
    } else {
        int n = max(2, (X + Y + K - 1) / K);
        if ((K * n - X - Y) % 2 == 1) {
            n++;
        }
        int x = (-K * (n - 2) + X + Y) / 2, y = (-K * n + X + Y) / 2;
        for (int i = 0; i < n; i++) {
            ans.push_back({x, y});
            int dx = min(X - x, K);
            x += dx;
            y += K - dx;
        }
    }

    for (auto &p : ans) {
        if (swapped) {
            swap(p.first, p.second);
        }
        p.first *= xs, p.second *= ys;
        cerr << p.first << " " << p.second << endl;
    }

    return true;
}

int main() {
    cin >> K;
    cin >> X >> Y;

    if (!solve()) {
        cout << -1 << endl;
        return 0;
    }

    cout << ans.size() << endl;
    for (auto &p : ans) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
