/*
[nikkei2019-qual] A - Subscribers
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

int N, A, B;

void solve() { cout << min(A, B) << " " << max(0, A + B - N) << endl; }

int main() {
    cin >> N >> A >> B;

    solve();

    return 0;
}
