/*
[abc105] A - AtCoder Crackers
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

int N, K;

ll solve() { return (N % K == 0) ? 0 : 1; }

int main() {
    cin >> N >> K;

    cout << solve() << endl;

    return 0;
}
