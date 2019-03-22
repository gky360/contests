/*
[tenka1-2018] F - Circular
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

const int MAX_N = 300000;
const ll MOD = 998244353;

int N;
int A[MAX_N * 2];
int b[MAX_N * 2];

ll solve() {
    if (count(A, A + N, 0) == 0) {
        return 0;
    }
    if (count(A, A + N, 0) == N) {
        ll ans = 1;
        for (int i = 1; i <= N; i++) {
            (ans *= i) %= MOD;
        }
        return ans;
    }

    vector<int> pos[MAX_N];
    for (int j = 0; j < N; j++) {
        if (A[j] == 0 && A[(j + N - 1) % N] > 0) {
            for (int i = 0; i < 2 * N; i++) {
                b[i] = A[(i + j) % N];
            }
            for (int i = 0; i < 2 * N; i++) {
                A[i] = b[i];
            }
            for (int i = 0; i < N; i++) {
                pos[A[i]].push_back(i);
            }
            break;
        }
    }

    ll ans = 1;
    set<int> empty, unused;
    ll rem = 0;
    for (int i = 0; i < N; i++) {
        empty.insert(i);
        empty.insert(i + N);
    }
    empty.insert(3 * N);

    int K = pos[0].size();
    for (int i = 0; i < N; i++) {
        int size = pos[i].size();
        if (size > K) {
            return 0;
        }
        if (size == 0) {
            (ans *= rem) %= MOD;
        } else {
            int l = pos[i][0], r = pos[i].back() + 1;
            if (size != r - l) {
                return 0;
            }
            for (int p : pos[i]) {
                empty.erase(p);
                empty.erase(p + N);
                unused.insert(p);
            }
            if (A[l + N - 1] > i && A[r] > i && size < K) {
                return 0;
            }
            if (A[l + N - 1] < i && A[r] < i) {
                (ans *= K - size + 1) %= MOD;
            }

            auto itr = unused.lower_bound(l - K + 1);
            while (itr != unused.end() && *itr < r) {
                auto itr2 = empty.lower_bound(*itr);
                if (*itr2 - *itr < K) {
                    itr = unused.lower_bound(*itr2);
                } else {
                    rem++;
                    itr = unused.erase(itr);
                }
            }
        }
        rem--;
    }

    return ans;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        A[i]--;
    }

    cout << solve() << endl;

    return 0;
}
