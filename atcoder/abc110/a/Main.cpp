/*
[abc110] A - Maximize the Formula
*/

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int ABC[3];

int solve() {
    sort(ABC, ABC + 3);

    return ABC[2] * 10 + ABC[1] + ABC[0];
}

int main() {
    cin >> ABC[0] >> ABC[1] >> ABC[2];

    cout << solve() << endl;

    return 0;
}
