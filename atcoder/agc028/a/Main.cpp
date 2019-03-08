/*
[agc028] A - Two Abbreviations
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

int gcd(int a, int b) {
    while (b > 0) {
        swap(b, a %= b);
    }
    return a;
}

int N, M;
string S, T;

ll solve() {
    int d = gcd(N, M);

    for (int i = 0, j = 0; i < N && j < M; i += N / d, j += M / d) {
        if (S[i] != T[j]) {
            return -1;
        }
    }

    return 1LL * N * M / d;
}

int main() {
    cin >> N >> M;
    cin >> S;
    cin >> T;

    cout << solve() << endl;

    return 0;
}
