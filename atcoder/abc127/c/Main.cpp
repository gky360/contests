/*
[abc127] C - Prison
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

const int MAX_M = 1e5;

int N, M;
int l[MAX_M], r[MAX_M];

ll solve() {
    int lr = *max_element(l, l + M);
    int rl = *min_element(r, r + M);
    return (rl >= lr) ? (rl - lr + 1) : 0;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> l[i] >> r[i];
    }

    cout << solve() << endl;

    return 0;
}
