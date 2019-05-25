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
    vector<pli> cb;
    for (int i = 0; i < M; i++) {
        cb.emplace_back(C[i], B[i]);
    }
    for (int i = 0; i < N; i++) {
        cb.emplace_back(A[i], 1);
    }
    sort(cb.begin(), cb.end());

    int rem = N;
    ll ans = 0;
    for (int i = cb.size() - 1; i >= 0; i--) {
        if (rem <= 0) {
            break;
        }
        int d = min(rem, cb[i].second);
        ans += cb[i].first * d;
        rem -= d;
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
