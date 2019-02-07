/*
[arc101] D - Median of Medians
*/

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

const int MAX_N = 100000;
const int MAX_A = 1e9;
const int MAX_BIT_IDX = 2 * MAX_N + 2;

template <typename T>
class BIT {
public:
    T b[MAX_BIT_IDX + 1];
    int n;
    void init(int num);
    T sum(int i);          // i : [0, n), returns sum of [0, i)
    void add(int i, T x);  // i : [0, n)
};

template <typename T>
void BIT<T>::init(int num) {
    n = num;
    for (int i = 0; i <= n; i++) {
        b[i] = 0;
    }
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
    for (i += 1; i <= n; i += i & -i) {
        b[i] += x;
    }
    return;
}

int N;
int a[MAX_N];

bool has_enough(int x) {
    int s[MAX_N + 1];
    s[0] = 0;
    for (int i = 1; i <= N; i++) {
        s[i] = (a[i - 1] >= x) ? 1 : -1;
    }
    for (int i = 1; i <= N; i++) {
        s[i] += s[i - 1];
    }

    BIT<int> bit;
    bit.init(2 * N + 2);
    ll inversion = 0;
    for (int i = 0; i <= N; i++) {
        inversion += i - bit.sum(s[i] + 1 + N);
        bit.add(s[i] + N, 1);
    }

    ll len = (N + 1LL) * N / 2LL;
    return len - inversion >= (len + 1) / 2;
}

ll solve() {
    int l = 0;
    int r = MAX_A + 1;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (has_enough(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    int ans = (r + l) / 2;
    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    cout << solve() << endl;

    return 0;
}
