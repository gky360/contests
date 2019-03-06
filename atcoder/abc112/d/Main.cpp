/*
[abc112] D - Partition
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

const int MAX_M = 1e9;
const int MAX_P = 1e5;

int N, M;

ll solve() {
    vector<int> divs;
    for (int i = 1; i * i <= M; i++) {
        if (M % i == 0) {
            divs.push_back(i);
            if (i * i != M) {
                divs.push_back(M / i);
            }
        }
    }
    sort(divs.begin(), divs.end(), greater<int>());

    for (int d : divs) {
        if (M / d >= N) {
            return d;
        }
    }
    return -1;
}

int main() {
    cin >> N >> M;

    cout << solve() << endl;

    return 0;
}
