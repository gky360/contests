/*
[soundhound2018-summer-qual] A - F
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

char solve(int a, int b) {
    if (a + b == 15) {
        return '+';
    } else if (a * b == 15) {
        return '*';
    }
    return 'x';
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << solve(a, b) << endl;

    return 0;
}
