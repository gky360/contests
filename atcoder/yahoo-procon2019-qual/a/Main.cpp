/*
[yahoo-procon2019-qual] A - Anti-Adjacency
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

int N, K;

bool solve() { return (N + 1) / 2 >= K; }

int main() {
    cin >> N >> K;

    cout << (solve() ? "YES" : "NO") << endl;

    return 0;
}
