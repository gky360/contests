/*
[abc128] C - Switches
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

const int MAX_M = 10;

int N, M;
int s[MAX_M];
int p[MAX_M];

bool can(int pat) {
    for (int i = 0; i < M; i++) {
        int b = pat & s[i];
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (b & (1 << j)) {
                cnt++;
            }
        }
        if (cnt % 2 != p[i]) {
            return false;
        }
    }

    return true;
}

ll solve() {
    int ans = 0;
    for (int pat = 0; pat < (1 << N); pat++) {
        if (can(pat)) {
            ans++;
        }
    }

    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int sij;
            cin >> sij;
            s[i] = s[i] | (1 << (sij - 1));
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> p[i];
    }

    cout << solve() << endl;

    return 0;
}
