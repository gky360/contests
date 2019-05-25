/*
[abc127] A - Ferris Wheel
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

int A, B;

ll solve() {
    if (A >= 13) {
        return B;
    }
    if (A >= 6) {
        return B / 2;
    }
    return 0;
}

int main() {
    cin >> A >> B;

    cout << solve() << endl;

    return 0;
}
