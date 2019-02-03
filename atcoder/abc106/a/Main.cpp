/*
[abc106] A - Garden
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

int A, B;

ll solve() { return A * B - A - B + 1; }

int main() {
    cin >> A >> B;

    cout << solve() << endl;

    return 0;
}
