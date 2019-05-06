/*
[agc029] C - Lexicographic constraints
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

const int MAX_N = 2e5;

int N;
ll A[MAX_N];

bool can(int n) {
    map<ll, int> m;
    for (int i = 1; i < N; i++) {
        if (A[i] > A[i - 1]) {
            continue;
        }
        m.erase(m.upper_bound(A[i]), m.end());
        if (m.find(A[i]) == m.end()) {
            if (n == 1) {
                return false;
            }
            m[A[i]] = 1;
        } else {
            m[A[i]]++;
            for (int j = A[i]; m[j] == n; j--) {
                if (j == 1) {
                    return false;
                }
                m[j] = 0;
                if (m.find(j - 1) == m.end()) {
                    m[j - 1] = 1;
                } else {
                    m[j - 1]++;
                }
            }
        }
    }

    return true;
}

ll solve() {
    int ng = 0;
    int ok = MAX_N;
    while (ok - ng > 1) {
        int m = (ok + ng) / 2;
        if (can(m)) {
            ok = m;
        } else {
            ng = m;
        }
    }

    return ok;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << solve() << endl;

    return 0;
}
