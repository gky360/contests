/*
[abc185] F - Range Xor Query
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
const int MAX_Q = 300000;

template <typename T>
class BIT {
public:
    vector<T> b;
    BIT(int n) : b(n + 1) {}
    T sum(int i) {  // i : [0, n], returns sum of [0, i)
        T s = 0;
        for (; i > 0; i -= i & -i) s ^= b[i];
        return s;
    }
    void add(int i, T x) {  // i : [0, n)
        for (i += 1; i < (int)b.size(); i += i & -i) b[i] ^= x;
    }
};

int N, Q;
int A[MAX_N];
int T[MAX_Q], X[MAX_Q], Y[MAX_Q];

void solve() {
    BIT<int> bit(N);
    REP(i, N) bit.add(i, A[i]);
    REP(q, Q) {
        if (T[q] == 1) {
            bit.add(X[q] - 1, Y[q]);
        } else {
            int ans = bit.sum(Y[q]) ^ bit.sum(X[q] - 1);
            cout << ans << endl;
        }
    }
}

int main() {
    cin >> N >> Q;
    REP(i, N) cin >> A[i];
    REP(i, Q) cin >> T[i] >> X[i] >> Y[i];

    solve();

    return 0;
}
