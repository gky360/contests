/*
[agc006] E - Rotate 3x3
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
#define ALL(c) (c).begin(), (c).end()

const int MAX_N = 1e5;
const int MAX_BIT_IDX = MAX_N;

template <typename T>
class BIT {
public:
    vector<T> b;
    BIT(int n) : b(n + 1) {}
    T sum(int i) {  // i : [0, n], returns sum of [0, i)
        T s = 0;
        for (; i > 0; i -= i & -i) {
            s += b[i];
        }
        return s;
    }
    void add(int i, T x) {  // i : [0, n)
        for (i += 1; i < (int)b.size(); i += i & -i) {
            b[i] += x;
        }
        return;
    }
};

int N;
ll a[3][MAX_N];
map<ll, int> at[2];
vector<int> v[2];
int fl[2];

bool solve() {
    for (int i = 0; i < N; i++) {
        ll p = 1 + i * 3, q = p + 1, r = q + 1;
        if (i % 4 >= 2) {
            swap(p, r);
        }
        at[i % 2][(p << 40) | (q << 20) | r] = i / 2;
    }
    for (int i = 0; i < N; i++) {
        if (i % 4 >= 2) {
            swap(a[0][i], a[2][i]);
        }
        ll k1 = (a[0][i] << 40) | (a[1][i] << 20) | a[2][i];
        ll k2 = (a[2][i] << 40) | (a[1][i] << 20) | a[0][i];
        if (at[i % 2].count(k1)) {
            v[i % 2].push_back(at[i % 2][k1]);
        } else if (at[i % 2].count(k2)) {
            v[i % 2].push_back(at[i % 2][k2]);
            fl[i % 2] ^= 1;
        } else {
            return false;
        }
    }

    for (int b = 0; b < 2; b++) {
        BIT<int> bit((N + 1) / 2);
        ll inv = 0;
        for (int i = v[b].size() - 1; i >= 0; i--) {
            inv += bit.sum(v[b][i]);
            bit.add(v[b][i], 1);
        }

        if (inv % 2 != fl[b ^ 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    cin >> N;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    cout << (solve() ? "Yes" : "No") << endl;

    return 0;
}
