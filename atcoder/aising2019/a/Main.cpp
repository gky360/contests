/*
[aising2019] A - Bulletin Board
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

int N, H, W;

ll solve() { return (N - H + 1) * (N - W + 1); }

int main() {
    cin >> N >> H >> W;

    cout << solve() << endl;

    return 0;
}
