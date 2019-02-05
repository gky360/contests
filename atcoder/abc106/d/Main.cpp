/*
[abc106] D - AtCoder Express 2
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

const int MAX_N = 500;
const int MAX_M = 200000;

int N, M, Q;
int L[MAX_M], R[MAX_M];
int imos[MAX_N + 1][MAX_N + 1];

void do_imos() {
    for (int i = 0; i < M; i++) {
        imos[L[i]][R[i]]++;
    }
    for (int j = 0; j <= N; j++) {
        for (int i = 0; i < N; i++) {
            imos[i + 1][j] += imos[i][j];
        }
    }
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < N; j++) {
            imos[i][j + 1] += imos[i][j];
        }
    }
}

ll solve(int p, int q) { return imos[N][q] - imos[p - 1][q]; }

int main() {
    cin >> N >> M >> Q;
    for (int i = 0; i < M; i++) {
        cin >> L[i] >> R[i];
    }

    do_imos();

    for (int i = 0; i < Q; i++) {
        int p, q;
        cin >> p >> q;
        cout << solve(p, q) << endl;
    }

    return 0;
}
