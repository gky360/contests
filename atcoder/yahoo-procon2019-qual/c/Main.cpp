/*
[yahoo-procon2019-qual] C - When I hit my pocket...
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

ll K, A, B;

ll solve() {
    return max(K + 1, (K - A + 1) / 2 * (B - A) + A + (K - A + 1) % 2);
}

int main() {
    cin >> K >> A >> B;

    cout << solve() << endl;

    return 0;
}
