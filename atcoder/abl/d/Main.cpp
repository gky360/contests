/*
[abl] D - Flat Subsequence
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

const int MAX_N = 300000;
const int MAX_A = 300000;

template <typename T>
class RMQMax {
public:
    int n;
    vector<T> data;
    RMQMax(int _n) {
        n = 1;
        while (n < _n) n <<= 1;
        data.resize(2 * n - 1);
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
        if (r <= a || b <= l) return 0;
        if (a <= l && r <= b) return data[k];
        return max(query(a, b, k * 2 + 1, l, (l + r) / 2),
                   query(a, b, k * 2 + 2, (l + r) / 2, r));
    }
};

int N, K;
int A[MAX_N];

ll solve() {
    RMQMax<int> rmq(MAX_A + 1);

    REP(i, N) {
        int l = rmq.query(max(0, A[i] - K), min(MAX_A, A[i] + K) + 1);
        rmq.update(A[i], l + 1);
    }

    int ans = rmq.query(0, MAX_A + 1);
    return ans;
}

int main() {
    cin >> N >> K;
    REP(i, N) cin >> A[i];

    cout << solve() << endl;

    return 0;
}
