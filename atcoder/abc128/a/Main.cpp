/*
[abc128] A - Apple Pie
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

int A, P;

ll solve() { return (A * 3 + P) / 2; }

int main() {
    cin >> A >> P;

    cout << solve() << endl;

    return 0;
}
