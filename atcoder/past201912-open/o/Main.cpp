/*
[past201912-open] O - 持久戦 / Endurance
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;

template <typename T>
class RMQ {
public:
    int n;
    vector<T> data;
    RMQ(int _n) {
        n = 1;
        while (n < _n) {
            n <<= 1;
        }
        data.resize(2 * n - 1);
        fill(data.begin(), data.end(), 0.0);
    }
    void update(int k, T a) {
        k += n - 1;
        data[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            data[k] = max(data[k * 2 + 1], data[k * 2 + 2]);
        }
    }
    T query(int a, int b) { return query(a, b, 0, 0, n); }

private:
    T query(int a, int b, int k, int l, int r) {  // [a, b), [l, r)
        if (r <= a || b <= l) {
            return 0.0;
        }
        if (a <= l && r <= b) {
            return data[k];
        }
        return max(query(a, b, k * 2 + 1, l, (l + r) / 2),
                   query(a, b, k * 2 + 2, (l + r) / 2, r));
    }
};

int N;
int A[MAX_N][6];

double solve() {
    vector<pii> ais;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++) {
            ais.push_back({A[i][j], i});
        }
    }
    sort(ALL(ais), greater<pii>());

    RMQ<double> rmq(N);
    for (auto& ai : ais) {
        int n = ai.second;
        double ea = rmq.query(0, N);
        double en = rmq.query(n, n + 1);
        rmq.update(n, en + (ea + 1.0) / 6.0);
    }

    double ans = rmq.query(0, N) + 1.0;

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> A[i][j];
        }
    }

    cout << setprecision(16) << solve() << endl;

    return 0;
}
