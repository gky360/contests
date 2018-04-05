// ABC089
// D - Practical Skill Test

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

const int INF = 1e9;
const int MAX_W = 300, MAX_H = 300;
const int MAX_D = MAX_W * MAX_H;

template <typename T>
class BIT {
public:
    vector<T> b;
    int n;
    void init(int num);
    T sum(int i);
    void add(int i, T x);
};

template <typename T>
void BIT<T>::init(int num) {
    n = num;
    b.clear();
    b.resize(n + 1);
    return;
}

template <typename T>
T BIT<T>::sum(int i) {
    T s = 0;

    for (; i > 0; i -= i & -i) {
        s += b[i];
    }
    return s;
}

template <typename T>
void BIT<T>::add(int i, T x) {
    for (; i <= n; i += i & -i) {
        b[i] += x;
    }
    return;
}

int operator-(pii p0, pii p1) {
    return abs(p0.first - p1.first) + abs(p0.second - p1.second);
}

int H, W, D;
int Q;
map<int, pii> n2l;
BIT<int> bit[MAX_D];

int main() {
    cin >> H >> W >> D;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int a;
            cin >> a;
            n2l[a - 1] = pii(i, j);
        }
    }
    for (int d = 0; d < D; d++) {
        bit[d].init(H * W / D + 1);
    }

    for (int d = 0; d < D; d++) {
        pii pre_hw, hw;
        hw = n2l.at(d);
        for (int n = d; n + D < H * W; n += D) {
            pre_hw = hw;
            hw = n2l.at(n + D);
            bit[d].add(n / D + 1, hw - pre_hw);
        }
    }

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int ans = bit[l % D].sum(r / D + 1 - 1) - bit[l % D].sum(l / D + 1 - 1);
        cout << ans << endl;
    }

    return 0;
}
