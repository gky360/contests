/*
[abc190] F - Shift and Inversions
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

const int MAX_N = 3e5;

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

int N;
int a[MAX_N];

void solve() {
    BIT<int> bit(N);

    ll ret = 0;
    REP(i, N) {
        ret += bit.sum(N) - bit.sum(a[i]);
        bit.add(a[i], 1);
    }

    vector<ll> ans(N);
    ans[0] = ret;
    for (int i = 1; i < N; i++) ans[i] = ans[i - 1] + N - 1 - 2 * a[i - 1];

    REP(i, N) cout << ans[i] << endl;
}

int main() {
    cin >> N;
    REP(i, N) cin >> a[i];

    solve();

    return 0;
}
