/*
[agc030] A - Poisonous Cookies
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

int A, B, C;

ll solve() { return min(C, A + B + 1) + B; }

int main() {
    cin >> A >> B >> C;

    cout << solve() << endl;

    return 0;
}
