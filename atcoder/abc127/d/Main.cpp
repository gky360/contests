/*
[abc127] D - Integer Cards
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

const int MAX_N = 1e5;
const int MAX_M = 1e5;

int N, M;
ll A[MAX_N];
int B[MAX_M];
ll C[MAX_M];
map<ll, int> m;

ll solve() {
    for (int i = 0; i < N; i++) {
        m[A[i]]++;
    }

    for (int i = 0; i < M; i++) {
        int b = B[i];
        while (b > 0 && m.begin()->first < C[i]) {
            auto &p = *m.begin();
            int d = min(b, p.second);
            b -= d;
            if (p.second - d == 0) {
                m.erase(p.first);
            } else {
                p.second -= d;
            }
            m[C[i]] += d;
        }
    }

    ll ans = 0;
    for (auto &p : m) {
        ans += p.first * p.second;
    }
    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i] >> C[i];
    }

    cout << solve() << endl;

    return 0;
}
