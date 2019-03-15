/*
[code-festival-2018-qualb] B - Tensai
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

const int MAX_N = 100;

int N, X;
int a[MAX_N], b[MAX_N];

ll solve() {
    int s = 0;
    int max_b = 0;
    for (int i = 0; i < N; i++) {
        s += a[i] * b[i];
        max_b = max(max_b, b[i]);
    }
    return s + max_b * X;
}

int main() {
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }

    cout << solve() << endl;

    return 0;
}
