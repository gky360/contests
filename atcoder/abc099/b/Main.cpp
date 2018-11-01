/*
[abc099] B - Stone Monument
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

int a, b;

ll solve() {
    ll n = b - a;
    return n * (n + 1) / 2 - b;
}

int main() {
    cin >> a >> b;

    cout << solve() << endl;

    return 0;
}
