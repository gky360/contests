/*
[soundhound2018-summer-qual] C - Ordinary Beauty
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

double solve(ll n, ll m, ll d) {
    ll r = (d == 0 ? n : (2 * (n - d)));
    return 1.0L * r * (m - 1) / (n * n);
}

int main() {
    ll n, m, d;

    cin >> n >> m >> d;

    cout << setprecision(10) << fixed << solve(n, m, d) << endl;

    return 0;
}
