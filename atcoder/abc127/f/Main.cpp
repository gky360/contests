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
typedef pair<ll, ll> pll;

const int MAX_Q = 2e5;
const int INF = 1e9 + 1;

struct Query {
    bool ty;
    int a, b;
};

int Q;
Query qs[MAX_Q];
multiset<int> ls = {-INF}, rs = {INF};

pll update(Query &q, ll fx) {
    int lx = *ls.rbegin();
    int rx = (ls.size() == rs.size()) ? *rs.begin() : lx;
    if (q.a < lx) {
        fx += lx - q.a;
    } else if (rx < q.a) {
        fx += q.a - rx;
    }
    fx += q.b;

    if (ls.size() > rs.size()) {
        rs.insert(q.a);
    } else {
        ls.insert(q.a);
    }
    auto lr = *ls.rbegin(), rl = *rs.begin();
    if (lr > rl) {
        ls.erase(--ls.end());
        rs.erase(rs.begin());
        ls.insert(rl);
        rs.insert(lr);
    }

    return {*ls.rbegin(), fx};
}

void solve() {
    pll ans = {0, 0};
    for (int i = 0; i < Q; i++) {
        if (qs[i].ty) {
            cout << ans.first << " " << ans.second << endl;
        } else {
            ans = update(qs[i], ans.second);
        }
    }
}

int main() {
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int tmp_ty;
        cin >> tmp_ty;
        qs[i].ty = (tmp_ty == 2);
        if (!qs[i].ty) {
            cin >> qs[i].a >> qs[i].b;
        }
    }
    solve();

    return 0;
}
