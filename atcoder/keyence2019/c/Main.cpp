/*
[keyence2019] C - Exam and Wizard
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

const int MAX_N = 1e5;

int N;
int A[MAX_N], B[MAX_N];

ll solve() {
    int d[MAX_N];
    for (int i = 0; i < N; i++) {
        d[i] = A[i] - B[i];
    }
    sort(d, d + N);

    ll s = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (d[i] >= 0) {
            break;
        }
        s += -d[i];
        ans++;
    }
    for (int i = N - 1; i >= 0; i--) {
        if (d[i] <= 0 || s <= 0) {
            break;
        }
        s -= d[i];
        ans++;
    }

    return s <= 0 ? ans : -1;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    cout << solve() << endl;

    return 0;
}
