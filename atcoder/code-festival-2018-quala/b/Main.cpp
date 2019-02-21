/*
[code-festival-2018-quala] B - みかん
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

const int MAX_M = 100;

int N, M, A, B;
int L[MAX_M], R[MAX_M];

ll solve() {
    int s = 0;
    for (int i = 0; i < N; i++) {
        bool is_a = false;
        for (int j = 0; j < M; j++) {
            if (L[j] <= i && i < R[j]) {
                is_a = true;
                break;
            }
        }
        s += is_a ? A : B;
    }
    return s;
}

int main() {
    cin >> N >> M >> A >> B;
    for (int i = 0; i < M; i++) {
        cin >> L[i] >> R[i];
        L[i]--;
    }

    cout << solve() << endl;

    return 0;
}
