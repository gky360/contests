/*
[bitflyer2018-final] C - 部分文字列と括弧
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
const int MAX_BIT_IDX = MAX_N + 1;

template <typename T>
class BIT {
public:
    T b[MAX_BIT_IDX + 1];
    int n;
    void init(int num);
    T sum(int i);          // i : [0, n)
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

    i++;
    for (; i > 0; i -= i & -i) {
        s += b[i];
    }
    return s;
}

template <typename T>
void BIT<T>::add(int i, T x) {
    i++;
    for (; i <= n; i += i & -i) {
        b[i] += x;
    }
    return;
}

string s;
int N;
map<int, vector<int>> mh;
BIT<int> bit;

ll solve() {
    int h = 0;
    mh[0].push_back(0);
    for (int i = 1; i <= N; i++) {
        h += (s[i - 1] == '(' ? 1 : -1);
        mh[h].push_back(i);
    }

    ll ans = 0;
    for (auto &p : mh) {
        vector<int> c = p.second;

        int li = 0;
        for (int ri = 0; ri < (int)c.size(); ri++) {
            while (li < ri && (bit.sum(c[ri]) - bit.sum(c[li]) > 0)) {
                li++;
            }
            ans += ri - li;
        }

        for (int i : c) {
            bit.add(i, 1);
        }
    }

    return ans;
}

int main() {
    cin >> s;
    N = s.size();
    bit.init(N + 1);

    cout << solve() << endl;

    return 0;
}
