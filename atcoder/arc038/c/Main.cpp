/*
[arc038] C - 茶碗と豆
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;
const int INF = 1e9 + 1;

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
        fill(data.begin(), data.end(), INF);
    }
    void update(int k, T a) {
        k += n - 1;
        data[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            data[k] = min(data[k * 2 + 1], data[k * 2 + 2]);
        }
    }
    T query(int a, int b) { return query(a, b, 0, 0, n); }

private:
    T query(int a, int b, int k, int l, int r) {  // [a, b), [l, r)
        if (r <= a || b <= l) {
            return INF;
        }
        if (a <= l && r <= b) {
            return data[k];
        }
        return min(query(a, b, k * 2 + 1, l, (l + r) / 2),
                   query(a, b, k * 2 + 2, (l + r) / 2, r));
    }
};

int N;
int C[MAX_N], A[MAX_N];

bool solve() {
    RMQ<int> rmq(N);
    for (int i = 0; i < N; i++) {
        rmq.update(i, -1);
    }
    rmq.update(0, 0);

    int ans = 0;
    for (int i = 1; i < N; i++) {
        int x = 0;
        for (int j = 19; j >= 0; j--) {
            if (rmq.query(0, x + (1 << j)) >= i - C[i]) {
                x += (1 << j);
            }
        }
        rmq.update(x, i);
        if (A[i] % 2) {
            ans ^= x;
        }
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> C[i] >> A[i];
    }

    cout << (solve() ? "First" : "Second") << endl;

    return 0;
}
