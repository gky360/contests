/*
[abc127] F - Absolute Minima
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int NONE = 1e9 + 1;
const int MAX_Q = 2e5;
const int MAX_BIT_IDX = MAX_Q;

template <typename T>
class BIT {
public:
    T b[MAX_BIT_IDX + 1];
    int n;
    void init(int num) {
        n = num;
        for (int i = 0; i <= n; i++) {
            b[i] = 0;
        }
        return;
    }
    T sum(int i) {  // i : [0, n), returns sum of [0, i)
        T s = 0;
        for (; i > 0; i -= i & -i) {
            s += b[i];
        }
        return s;
    }
    void add(int i, T x) {  // i : [0, n)
        for (i += 1; i <= n; i += i & -i) {
            b[i] += x;
        }
        return;
    }
};

int Q;
bool ty[MAX_Q];
int a[MAX_Q], b[MAX_Q];
BIT<ll> bit1, bit2;

void solve() {
    vector<int> ca(Q);
    for (int i = 0; i < Q; i++) {
        ca[i] = a[i];
    }
    sort(ca.begin(), ca.end());
    ca.erase(unique(ca.begin(), ca.end()), ca.end());
    for (int i = 0; i < Q; i++) {
        if (a[i] != NONE) {
            a[i] = lower_bound(ca.begin(), ca.end(), a[i]) - ca.begin();
        }
    }

    bit1.init(Q);
    bit2.init(Q);
    int cnt = 0;
    ll sb = 0;
    for (int i = 0; i < Q; i++) {
        if (ty[i]) {
            // answer
            int ng = -1;
            int ok = Q;
            while (ok - ng > 1) {
                int m = (ok + ng) / 2;
                if (bit1.sum(m + 1) >= (cnt + 1) / 2) {
                    ok = m;
                } else {
                    ng = m;
                }
            }

            int x = ca[ok];
            ll cnt_x = bit1.sum(ok) - (bit1.sum(Q) - bit1.sum(ok));
            ll sa = -bit2.sum(ok) + (bit2.sum(Q) - bit2.sum(ok));
            ll fx = sb + 1LL * x * cnt_x + sa;

            cout << x << " " << fx << endl;
        } else {
            // update
            cnt++;
            bit1.add(a[i], 1);
            bit2.add(a[i], ca[a[i]]);
            sb += b[i];
        }
    }
}

int main() {
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int tmp_ty;
        cin >> tmp_ty;
        ty[i] = (tmp_ty == 2);
        if (ty[i]) {
            a[i] = b[i] = NONE;
        } else {
            cin >> a[i] >> b[i];
        }
    }
    solve();

    return 0;
}
