/*
[abc103] D - Islands War
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

const int MAX_M = 100000;

int N, M;
pii ba[MAX_M];

ll solve() {
    sort(ba, ba + M);

    int ans = 0;
    int last = 0;
    for (pii p : ba) {
        int a = p.second;
        int b = p.first;
        if (a >= last) {
            last = b;
            ans++;
        }
    }

    return ans;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> ba[i].second >> ba[i].first;
        ba[i].second--;
        ba[i].first--;
    }

    cout << solve() << endl;

    return 0;
}
