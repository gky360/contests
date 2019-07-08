/*
[keyence2019] A - Beginning
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

vector<int> N(4);

bool solve() {
    sort(N.begin(), N.end());
    return N == vector<int>{1, 4, 7, 9};
}

int main() {
    for (int i = 0; i < 4; i++) {
        cin >> N[i];
    }

    cout << (solve() ? "YES" : "NO") << endl;

    return 0;
}
